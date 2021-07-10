#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, x;
		std::cin >> n >> x;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		LL mn = 0, mx = 0;
		for (int i = 0; i < n; ++i) {
			mn += a[i];
			mx += (a[i] + x - 1) / x;
		}
		std::cout << (mn + x - 1) / x << " " << mx << std::endl;
	}
	return 0;
}