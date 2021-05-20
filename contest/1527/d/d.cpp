#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> e(n);
		for (int i = 1; i < n; ++i) {
			int u, v;
			std::cin >> u >> v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		std::vector<int> sz(n + 1), son(n + 1, n), val(n + 1, n);
		std::function<void(int, int)> pdfs = [&](int u, int fa) {
			sz[u] = 1;
			for (auto v : e[u]) if (v != fa) {
				pdfs(v, u);
				sz[u] += sz[v];
				if (val[son[u]] > val[v]) son[u] = v;
			}
			val[u] = std::min(u, val[son[u]]);
		};
		pdfs(0, n);
		std::vector<LL> ans(n + 1);
		for (auto v : e[0]) ans[0] += 1LL * sz[v] * (sz[v] - 1) / 2;
		ans[1] = 1LL * n * (n - 1) / 2 - ans[0];
		int now = 1;
		while (now < n) {
			// 哇，我为什么是 n - sz[1] 啊，明明应该是 n - sz[son[0]] 啊！
			ans[now + 1] = 1LL * sz[now] * (n - sz[son[0]]);
			if (son[now] != now + 1) break;
			++now;
		}
		int tmp = now;
		++now;
		// watch(now);
		while (now < n) {
			// watch(now);
			ans[now + 1] = 1LL * sz[now] * sz[tmp];
			if (son[now] != now + 1) break;
			++now;
		}
		// for (int i = 0; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
		for (int i = 1; i < n; ++i) ans[i] -= ans[i + 1];
		for (int i = 0; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
	}
	return 0;
}