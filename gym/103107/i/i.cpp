#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int t;
		std::cin >> t;
		int sg = 0;
		for (int i = 0; i < t; ++i) {
			int n, m;
			std::cin >> n >> m;
			std::map<int, int> mp;
			for (int i = 0, x; i < n; ++i) {
				std::cin >> x;
				x = m - x - n + i + 1;
				if (x & 1) ++mp[x];
			}
			for (auto [x, c] : mp) sg ^= c;
		}
		std::cout << (sg ? "Alice" : "Bob") << '\n';
	}
	return 0;
}