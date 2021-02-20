#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 为了代码简洁，树的编号以 1 开始。
std::vector<LL> dsuOnTree(std::vector<std::vector<int>> &e, std::vector<int> &a, int rt = 1) {
	int n = a.size();
	// 预处理出重儿子
	std::vector<int> sz(n), son(n);
	std::function<int(int, int)> pdfs = [&](int u, int fa) -> int {
		sz[u] = 1;
		for (auto v : e[u]) if (v != fa) {
			sz[u] += pdfs(v, u);
			if (sz[v] > sz[son[u]]) son[u] = v;
		}
		return sz[u];
	};
	std::vector<int> mx(n);
	std::vector<LL> ans(n);
	std::function<std::map<int, int>(int, int)> dfs = [&](int u, int fa) -> std::map<int, int> {
		if (son[u] == 0) {
			mx[u] = 1;
			ans[u] = a[u];
			return {{a[u], 1}};
		}
		auto mp = dfs(son[u], u);
		mx[u] = mx[son[u]];
		ans[u] = ans[son[u]];
		auto deal = [&](int x, int c) {
			auto &it = mp[x];
			it += c;
			if (it > mx[u]) {
				mx[u] = it;
				ans[u] = x;
			} else if (it == mx[u]) {
				ans[u] += x;
			}
		};
		deal(a[u], 1);
		for (auto v : e[u]) if (v != fa && v != son[u]) {
			for (auto [v, x] : dfs(v, u)) {
				deal(v, x);
			}
		}
		return mp;
	};
	pdfs(rt, rt);
	dfs(rt, rt);
	return ans;
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	auto r = dsuOnTree(e, a);
	for (int i = 1; i <= n; ++i) std::cout << r[i] << " \n"[i == n];
	return 0;
}