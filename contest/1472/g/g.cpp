#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

using edge = std::vector<std::vector<std::pair<int, int>>>;
std::vector<LL> Dijkstra(int s, const edge &e) {
	std::priority_queue<std::pair<LL, int>> h;
	std::vector<LL> dist(e.size());
	std::vector<int> vis(e.size());
	dist[s] = 0;
	h.push({0, s});
	while (!h.empty()) {
		auto [d, u] = h.top();
		h.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		dist[u] = -d;
		for (auto [v, w] : e[u]) h.emplace(d - w, v);
	}
	return dist;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		edge e(n);
		for (int i = 0, u, v; i < m; ++i) {
			std::cin >> u >> v;
			e[--u].emplace_back(--v, 1);
		}
		auto dist = Dijkstra(0, e);
		std::vector<LL> p(n);
		std::iota(p.begin(), p.end(), 0);
		std::sort(p.begin(), p.end(), [&](int i, int j) {
			return dist[i] > dist[j];
		});
		std::vector<LL> r(n);
		for (int i = 0; i < n; ++i) {
			int u = p[i];
			r[u] = dist[u];
			for (auto [v, w] : e[u]) {
				if (dist[v] <= dist[u]) r[u] = std::min(r[u], dist[v]);
				else r[u] = std::min(r[u], r[v]);
			} 
		}
		for (int i = 0; i < n; ++i) std::cout << r[i] << " \n"[i == n - 1];
	}
	return 0;
}