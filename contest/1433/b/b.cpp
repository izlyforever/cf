#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		int now = 0, r = 0;
		while (now < n && a[now] == 0) ++now;
		while (now < n) {
			while (now < n && a[now] == 1) ++now;
			int tmp = now;
			while (now < n && a[now] == 0) ++now;
			if (now != n) r += now - tmp;
		}
		print(r);
	}
	return 0;
}