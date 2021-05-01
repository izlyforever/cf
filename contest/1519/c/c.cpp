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
		std::vector<int> a(n), b(n);
		for (auto &x : a) std::cin >> x;
		for (auto &x : b) std::cin >> x;
		LL s = std::accumulate(b.begin(), b.end(), 0LL);
		std::vector<std::vector<LL>> e(n + 1), c(n + 1);
		for (int i = 0; i < n; ++i) e[a[i]].emplace_back(b[i]);
		for (int i = 1; i <= n; ++i) if (e[i].size() > 1) std::sort(e[i].begin(), e[i].end(), std::greater<>());
		for (int i = 1; i <= n; ++i) if (int sz = e[i].size(); sz > 0) {
			c[sz].resize(sz);
			for (int j = 0; j < sz; ++j) c[sz][j] += e[i][j];
		}
		for (int i = 1; i <= n; ++i) if (c[i].size()) {
			for (int j = 1; j < i; ++j) c[i][j] += c[i][j - 1];
		}
		std::vector<LL> ans(n + 1);
		for (int i = 1; i <= n; ++i) if (c[i].size()) {
			for (int j = 1; j <= i; ++j) {
				ans[j] += c[i][i / j * j - 1];
			}
		}
		for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
	}
	return 0;
}