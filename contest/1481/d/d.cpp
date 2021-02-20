#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::string> a(n);
		for (auto &x : a) std::cin >> x;
		if (m % 2 == 1) {
			std::cout << "YES\n";
			for (int i = 0; i <= m; ++i) std::cout << (i % 2 + 1) << " \n"[i == m];
		} else {
			int u, v;
			for (u = 0; u < n; ++u) {
				for (v = 0; v < u; ++v) {
					if (a[u][v] == a[v][u]) break;
				}
				if (v < u) break;
			}
			if (u < n) {
				std::cout << "YES\n";
				for (int i = 0; i <= m; ++i) std::cout << (i % 2 ? u + 1 : v + 1) << " \n"[i == m];
			} else if (n == 2) {
				std::cout << "NO\n";
			} else {
				std::cout << "YES\n";
				int x = 0, y = 1, z = 2;
				if (a[x][y] != a[y][z]) {
					if (a[x][y] == a[x][z]) std::swap(y, z);
					else {
						std::tie(x, y, z) = std::make_tuple(z, x, y);
					}
				}
				if (m % 4 == 0) {
					std::vector<int> r{y, z, y, x};
					for (int i = 0; i <= m; ++i) std::cout << r[i % r.size()] + 1 << " \n"[i == m];
				} else {
					std::vector<int> r{x, y, z, y};
					for (int i = 0; i <= m; ++i) std::cout << r[i % r.size()] + 1 << " \n"[i == m];
				}
			}
		}
	}
	return 0;
}