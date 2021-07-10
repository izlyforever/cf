#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n), b(n), c(n);
	for (auto &x : a) std::cin >> x;
	std::string x, y;
	for (int i = 0; i < m; ++i) {
		if (i & 1) {
			x += 'R';
			y += 'W';
		} else {
			x += 'W';
			y += 'R';
		}
	}
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			b[i] = x;
			c[i] = y;
		} else {
			b[i] = y;
			c[i] = x;
		}
	}
	auto check = [&](const std::vector<std::string> &d) -> bool {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) if (a[i][j] != '.' && a[i][j] != d[i][j]) {
				return false;
			}
		}
		return true;
	};
	if (check(b)) {
		std::cout << "YES\n";
		for (auto &x : b) std::cout << x << '\n';
	} else if (check(c)) {
		std::cout << "YES\n";
		for (auto &x : c) std::cout << x << '\n';
	} else {
		std::cout << "NO\n";
	}
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas; // 根据情况注释掉
	while (cas--) {
		solve();
	}
	return 0;
}