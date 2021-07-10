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
		std::vector<std::vector<int>> e(n), g(n);
		for (int i = 1, x; i < n; ++i) {
			std::cin >> x;
			e[--x].emplace_back(i);
		}
		for (int i = 1, x; i < n; ++i) {
			std::cin >> x;
			g[--x].emplace_back(i);
		}
		std::vector<int> in(n), out(n);
		int timer = 0;
		std::function<void(int)> pdfs = [&](int u) {
			in[u] = timer++;
			for (auto v : g[u]) pdfs(v);
			out[u] = timer;
		};
		pdfs(0);
		std::set<std::pair<int, int>> S;
		auto add = [&](int u) {
			auto it = S.lower_bound({in[u], u});
			if (it != S.end() && out[it->second] <= out[u]) return -2; // 无效节点
			if (it == S.begin()) return -1;
			--it;
			int res = it->second;
			if (out[res] < out[u]) return -1;
			S.erase(it);
			return res;
		};
		int ans = 0;
		std::function<void(int)> dfs = [&](int u) {
			int res = add(u);
			if (res != -2) S.insert({in[u], u});
			ans = std::max(ans, (int)S.size());
			for (auto v : e[u]) dfs(v);
			if  (res != -2) {
				S.erase({in[u], u});
				if (res != -1) S.insert({in[res], res});
			}
		};
		dfs(0);
		std::cout << ans << '\n';
	}
	return 0;
}