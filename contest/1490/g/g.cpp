#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n), p(n);
		std::vector<LL> b(n);
		LL sm = 0;
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			sm += x;
			if (b.empty() || b.back() < sm) {
				b.emplace_back(sm);
				p.emplace_back(i);
			}
		}
		auto solve = [&](int x) -> LL {
			if (x <= b.back()) {
				int it = std::lower_bound(b.begin(), b.end(), x) - b.begin();
				return p[it];
			}
			if (sm <= 0) return -1;
			int t = (x - b.back() + sm - 1) / sm;
			x -= t * sm;
			LL r = LL(n) * t;
			int it = std::lower_bound(b.begin(), b.end(), x) - b.begin();
			return r + p[it];
		};
		for (int i = 0, x; i < m; ++i) {
			std::cin >> x;
			std::cout << solve(x) << " ";
		}
		std::cout << "\n";
	}
	return 0;
}