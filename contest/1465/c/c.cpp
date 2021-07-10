#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> e(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			std::cin >> x >> y;
			if (x != y) {
				--x; --y;
				e[x].emplace_back(y);
				e[y].emplace_back(x);
			}
		}
		int r = 0;
		std::vector<int> vis(n);
		bool flag = true;
		auto bfs = [&](int x) -> int {
			std::queue<int> Q;
			Q.push(x);
			vis[x] = 1;
			int r = 0;
			while (!Q.empty()) {
				int u = Q.front();
				r += e[u].size();
				Q.pop();
				if (e[u].size() == 1) flag = false;
				for (auto v : e[u]) if (!vis[v]) {
					Q.push(v);
					vis[v] = 1;
				}
			}
			return r / 2;
		};
		for (int i = 0; i < n; ++i) if (e[i].size() > 0 && !vis[i]) {
			r += bfs(i);
			if (flag) ++r;
			flag = true;
		}
		std::cout << r << std::endl;
	}
	return 0;
}