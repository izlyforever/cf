#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<std::set<int>> g(n + 1);
		for (int i = 1; i < n; ++i) {
			int u, v;
			std::cin >> u >> v;
			g[u].insert(v);
			g[v].insert(u);
		}
		std::vector<int> son(n + 1);
		for (int i = 1; i <= n; ++i) son[i] = g[i].size() - 1;
		++son[1];
		std::vector<std::set<std::pair<int, int>>> e(n + 1);
		for (int i = 1; i <= n; ++i) {
			for (auto x : g[i]) e[i].insert({-son[x], x});
		}
		std::vector<std::pair<int, int>> cut, add;
		std::function<void(int, int)> dfs = [&](int u, int fa) {
			for (auto [_, v] : e[u]) if (v != fa) dfs(v, u);
			if (son[u] >= 2) {
				if (g[u].count(fa)) {
					g[u].erase(fa);
					g[fa].erase(u);
					cut.emplace_back(u, fa);
					--son[fa];
				}
			}
			for (auto [_, v] : e[u]) if (v != fa && son[u] > 2) {
				if (g[u].count(v)) {
					g[u].erase(v);
					g[v].erase(u);
					cut.emplace_back(u, v);
					--son[u];
				}
			}
		};
		dfs(1, 0);
		std::vector<int> vis(n + 1);
		std::vector<std::pair<int, int>> p;
		std::vector<int> tmp;
		std::function<void(int, int)> find = [&](int u, int fa) {
			vis[u] = 1;
			if (g[u].size() <= 1) tmp.emplace_back(u);
			for (auto v : g[u]) if (v != fa) {
				find(v, u);
			}
		};
		for (int i = 1; i <= n; ++i) if (!vis[i]) {
			tmp.clear();
			find(i, 0);
			p.push_back({tmp[0], tmp.back()});
		}
		for (int i = 1; i < p.size(); ++i) {
			add.emplace_back(p[i - 1].second, p[i].first);
		}
		int sz = cut.size();
		std::cout << sz << '\n';
		for (int i = 0; i < sz; ++i) {
			std::cout << cut[i].first << ' ' << cut[i].second << ' ' << add[i].first << ' ' << add[i].second << '\n';
		}
	}
	return 0;
}