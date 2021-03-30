#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	int k2 = k * 2;
	std::vector<std::vector<int>> e(n);
	for (int i = 1, x, y; i < n; ++i) {
		std::cin >> x >> y;
		--x; --y;
		e[x].emplace_back(y);
		e[y].emplace_back(x);
	}
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	std::vector<std::vector<int>> b(n, std::vector<int>(2 * k));
	auto c = b; // 表示父节点上的异或和
	std::function<void(int, int)> preDfs = [&](int u, int fa) {
		b[u][0] = a[u];
		for (auto v : e[u]) if (v != fa) {
			preDfs(v, u);
			for (int i = 0; i < k2; ++i) {
				b[u][(i + 1) % k2] ^= b[v][i];
			}
		}
	};
	preDfs(0, 0);
	std::vector<int> ans(n);
	std::function<void(int, int)> dfs = [&](int u, int fa) {
		for (int i = k; i < k2; ++i) {
			ans[u] ^= b[u][i] ^ c[u][i];
		}
		for (auto v : e[u]) if (v != fa) {
			for (int i = 0; i < k2; ++i) {
				c[v][(i + 1) % k2] = c[u][i] ^ b[u][i] ^ b[v][(i + k2 - 1) % k2];
			}
			dfs(v, u);
		}
	};
	dfs(0, 0);
	for (auto x : ans) std::cout << std::min(1, x) << ' ';
	std::cout << '\n';
	return 0;
}