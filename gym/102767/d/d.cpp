#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
const int M = 1e9 + 7;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::map<int, int> mp;
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			++mp[-x];
		}
		std::cout << [&]() -> LL {
			if (mp.begin()->second > 1) return 0;
			mp.erase(mp.begin());
			int r = 1;
			for (auto [x, y] : mp) {
				if (y > 2) return 0;
				if (y == 1) r = r * 2 % M;
			}
			return r;
		}() << std::endl;
	}
	return 0;
}