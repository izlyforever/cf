#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 2; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	std::vector<std::tuple<int, int, int, int>> ans;
	auto f = [&](int x) {
		std::vector<int> sz(n + 1), son(n + 1), a(n + 1);
		std::function<void(int, int)> pdfs = [&](int u, int fa) {
			++sz[u];
			for (auto v : e[u]) if (v != fa) {
				pdfs(v, u);
				sz[u] += sz[v];
				if (sz[son[u]] < sz[v]) son[u] = v;
			}
		};
		std::function<void(int, int)> dfs = [&](int u, int fa) {
			if (son[u] == 0) {
				a[u] = u;
				return;
			}
			dfs(son[u], u);
			a[u] = a[son[u]];
			for (auto v : e[u]) if (v != fa && v != son[u]) {
				dfs(v, u);
				ans.emplace_back(v, u, a[u], v);
				a[u] = a[v];
			}
		};
		pdfs(x, 0);
		dfs(x, 0);
	};
	int u, v;
	std::cin >> u >> v;
	f(u); f(v);
	std::cout << ans.size() << '\n';
	for (auto [x1, y1, x2, y2] : ans) std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		solve();
	}
	return 0;
}