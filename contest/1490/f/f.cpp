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
		std::map<int, int> mp0, mp;
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			++mp0[x];
		}
		for (auto [x, y] : mp0) ++mp[y];
		// mp[i] 表示满足（数组 a 中值为 x 恰好有 i 个）的 x 的个数。
		std::vector<int> c;
		for (auto [x, y] : mp) c.emplace_back(y);
		for (int i = c.size() - 2; i >= 0; --i) c[i] += c[i + 1];
		int ans = 0, i = 0;
		for (auto [x, y] : mp) {
			ans = std::max(ans, x * c[i++]);
		}
		std::cout << n - ans << "\n";
	}
	return 0;
}