#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		LL c[2]{};
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
			c[i % 2] += a[i];
		}
		int t = c[0] > c[1];
		for (int i = 0; i < n; ++i) if (i % 2 == t) a[i] = 1;
		for (auto &x : a) std::cout << x << " ";
		std::cout << std::endl;
	}
	return 0;
}