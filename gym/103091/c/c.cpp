#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int s, n;
	std::cin >> s >> n;
	std::map<int, int> mp;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		++mp[x];
	}
	std::vector<std::pair<int, int>> a;
	int cur = 0;
	for (auto [x, c] : mp) {
		cur += c;
		a.emplace_back(cur, x);
	}
	int q;
	std::cin >> q;
	while (q--) {
		int x;
		std::cin >> x;
		auto it = std::upper_bound(a.begin(), a.end(), std::pair(x, INT_MAX));
		std::cout << (it == a.end() ? s : it->second - 1) << '\n';
	}
	return 0;
}