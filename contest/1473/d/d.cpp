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
		std::string s;
		std::cin >> n >> m >> s;
		std::vector<int> c(n + 2);
		std::vector<std::pair<int, int>> a(n + 2), b(n + 2);
		int now = 0, mx = 0, mn = 0;
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == '+') {
				mx = std::max(mx, ++now);
			} else {
				mn = std::min(mn, --now);
			}
			a[i] = {mn, mx};
			c[i] = now;
		}
		int np = 0, nq = 0;
		for (int i = n; i > 0; --i) {
			if (s[i - 1] == '+') {
				++np;
				nq = std::min(++nq, 0);
			} else {
				--nq;
				np = std::max(--np, 0);
			}
			b[i] = {nq, np};
		}
		while (m--) {
			int l, r;
			std::cin >> l >> r;
			std::cout << std::max(a[l - 1].second, c[l - 1] + b[r + 1].second) 
			- std::min(a[l - 1].first, c[l - 1] + b[r + 1].first) + 1 << std::endl; 
		}
	}
	return 0;
}