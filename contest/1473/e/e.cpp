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
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	edge e(4 * n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u; --v;
		for (int t = 0; t < 2; ++t) {
			for (int j = 0; j < 4; ++j) e[4 * u + j].emplace_back(4 * v + j, w);
			e[4 * u].emplace_back(4 * v + 1, 0);
			e[4 * u].emplace_back(4 * v + 2, 2 * w);
			e[4 * u].emplace_back(4 * v + 3, w);
			e[4 * u + 1].emplace_back(4 * v + 3, 2 * w);
			e[4 * u + 2].emplace_back(4 * v + 3, 0);
			std::swap(u, v);
		}
	}
	auto dist = Dijkstra(0, e);
	for (int i = 7; i < 4 * n; i += 4) std::cout << dist[i] << " ";
	std::cout << "\n";
	return 0;
}