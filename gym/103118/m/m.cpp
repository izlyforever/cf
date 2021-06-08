#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	// std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::string> c(n);
		for (auto &x : c) std::cin >> x;
		auto a = c, b = c;
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				for (int j = 1; j < m - 1; ++j) a[i][j] = '1';
			} else {
				for (int j = 1; j < m - 1; ++j) b[i][j] = '1';
			}
			a[i][0] = b[i][m - 1] = '1';
		}
		for (auto &x : a) std::cout << x << '\n';
		for (auto &x : b) std::cout << x << '\n';
	}
	return 0;
}