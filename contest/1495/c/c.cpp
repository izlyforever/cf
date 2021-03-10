#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	// freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::string> a(n);
		for (auto &x : a) std::cin >> x;
		for (int i = 0; i < n; i += 3) {
			a[i] = std::string(m, 'X');
			if (i + 3 < n) {
				if (m == 1 || (a[i + 1][1] == '.' && a[i + 2][1] == '.')) {
					a[i + 1][0] = a[i + 2][0] = 'X';
				} else {
					a[i + 1][1] = a[i + 2][1] = 'X';
				}
			} else if (i + 2 < n) {
				for (int j = 0; j < m; ++j) if (a[i + 2][j] == 'X') a[i + 1][j] = 'X';
			}
		}
		for (auto &x : a) std::cout << x << "\n";
	}
	return 0;
}