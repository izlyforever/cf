#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> a(n, std::vector<int>(m));
		std::vector<int> p(n * m + 1), b(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cin >> a[i][j];
				p[a[i][j]] = i;
			}
		}
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			b[i] = p[x];
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 0, x; j < n; ++j) {
				std::cin >> x;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				std::cout << a[b[i]][j] << " \n"[j == m - 1];
			}
		}
	}
	return 0;
}