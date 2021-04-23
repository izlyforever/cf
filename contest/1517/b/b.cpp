#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> a(n, std::vector<int>(m)), b(m, std::vector<int>(n));
		for (auto &x : a) for (auto &i : x) std::cin >> i;
		for (int i = 0; i < n; ++i) std::sort(a[i].begin(), a[i].end(), std::greater<>());
		std::set<std::pair<int, int>> S;
		for (int i = 0; i < n; ++i) S.insert({a[i].back(), i});
		for (int i = 0; i < m; ++i) {
			auto [val, id] = *S.begin();
			S.erase(*S.begin());
			b[i][id] = val;
			a[id].pop_back();
			if (!a[id].empty()) S.insert({a[id].back(), id});
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) if (b[i][j] == 0) {
				b[i][j] = a[j].back();
				a[j].pop_back();
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cout << b[j][i] << " \n"[j == m - 1];
			}
		}
	}
	return 0;
}