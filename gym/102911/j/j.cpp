#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::set<int>> e(m);
	std::map<std::string, std::vector<int>> mp;
	for (int i = 0, x; i < m; ++i) {
		std::cin >> x;
		while (x--) {
			std::string tmp;
			std::cin >> tmp;
			mp[tmp].emplace_back(i);
		}
	}
	std::vector<int> val(m);
	auto solve = [&]() {
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			auto a = it ->second;
			if (a.size() <= 1) continue;
			if (a.size() > 2) return 0;
			e[a[0]].insert(a[1]);
			e[a[1]].insert(a[0]);
		}
		auto bfs = [&](int x) {
			std::map<int, int> vis;
			std::queue<int> Q;
			Q.push(x);
			vis[x] = 1;
			while (!Q.empty()) {
				int u = Q.front();
				Q.pop();
				for (auto v : e[u]) {
					if (vis[v]) {
						if (vis[v] != 3 - vis[u]) return 0;
					} else {
						Q.push(v);
						vis[v] = 3 - vis[u];
					}
				}
			}
			int cnt[3]{};
			for (auto it = vis.begin(); it != vis.end(); ++it) ++cnt[it->second];
			if (cnt[1] > cnt[2]) {
				for (auto it = vis.begin(); it != vis.end(); ++it) {
					val[it->first] = it->second;
				}
			} else {
				for (auto it = vis.begin(); it != vis.end(); ++it) {
					val[it->first] = 3 - it->second;
				}
			}
			return 1;
		};
		for (int i = 0; i < m; ++i) if (val[i] == 0) {
			if (!bfs(i)) return 0;
		}
		return 1;
	};
	if (solve()) {
		std::cout << "YES\n";
		for (int i = 0; i < m; ++i) {
			std::cout << (val[i] == 1 ? "Saturday" : "Sunday") << "\n";
		}
	} else std::cout << "NO\n";
	return 0;
}