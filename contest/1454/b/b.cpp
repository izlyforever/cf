#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
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
		for (int i = 1, x; i <= n; ++i) {
			std::cin >> x;
			if (mp[x] == 0) mp[x] = i;
			else mp[x] = -1;
		}
		int ans = [&]() {
			for (auto it = mp.begin(); it != mp.end(); ++it) {
				if (it->second != -1) return it->second;
			}
			return -1;
		}();
		std::cout << ans << std::endl;
	}
	return 0;
}