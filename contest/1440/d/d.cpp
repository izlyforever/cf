#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::unordered_set<int>> e(n);
	for (int i = 0, x, y; i < m; ++i) {
		std::cin >> x >> y;
		--x; --y;
		e[x].insert(y);
		e[y].insert(x);
	}
	std::set<std::pair<int, int>> d;
	for (int i = 0; i < n; ++i) d.insert({e[i].size(), i});
	auto check = [&](int u) -> bool {
		std::vector<int> tmp(e[u].begin(), e[u].end());
		for (int i = 0; i < tmp.size(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (e[tmp[i]].count(tmp[j]) == 0) return false; 
			}
		}
		return true;
	};
	auto del = [&](int u) {
		for (auto v : e[u]) {
			d.erase({e[v].size(), v});
			e[v].erase(u);
			d.insert({e[v].size(), v});
			--m;
		}
	};
	while (!d.empty()) {
		int du = d.begin()->first;
		int u = d.begin()->second;
		if (du >= k) {
			std::cout << 1 << " " << d.size() << "\n";
			for (auto it = d.begin(); it != d.end(); ++it) {
				std::cout << (it->second + 1) << " ";
			}
			std::cout << "\n";
			return;
		}
		if (du == k - 1 && k - 1 <= m * 2 / k && check(u)) {
			std::cout << 2 << "\n";
			std::cout << u + 1 << " ";
			for (auto x : e[u]) std::cout << x + 1 << " ";
			std::cout << "\n";
			return;
		}
		d.erase(d.begin());
		del(u);
	}
	std::cout << "-1\n";
}
 
int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		solve();
	}
	return 0;
}