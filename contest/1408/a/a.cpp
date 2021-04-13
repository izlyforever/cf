#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n), b(n), c(n), p(n);
		for (auto &x : a) std::cin >> x;
		for (auto &x : b) std::cin >> x;
		for (auto &x : c) std::cin >> x;
		p[0] = a[0];
		for (int i = 1; i < n - 1; ++i) {
			if (a[i] == p[i - 1]) p[i] = b[i];
			else p[i] = a[i];
		}
		if (p[n - 2] != a[n - 1] && p[0] != a[n - 1]) {
			p[n - 1] = a[n - 1];
		} else if (p[n - 2] != b[n - 1] && p[0] != b[n - 1]) {
			p[n - 1] = b[n - 1];
		} else {
			p[n - 1] = c[n - 1];
		}
		for (auto &x : p) std::cout << x << " ";
		println;
	}
	return 0;
}