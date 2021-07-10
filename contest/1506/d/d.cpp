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
		std::map<int, int> mp;
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			++mp[x];
		}
		int mx = 0;
		for (auto [id, cnt]: mp) mx = std::max(mx, cnt);
		if (n > mx * 2) {
			std::cout << n % 2 << '\n';
		} else {
			std::cout << mx - (n - mx) << '\n';
		}
	}
	return 0;
}