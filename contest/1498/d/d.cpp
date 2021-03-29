#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	const int M = 1e5;
	while (cas--) {
		int n, m;
		LL xx;
		std::vector<int> a(m + 1, -1);
		a[0] = 0;
		std::set<int> S(n);
		for (int i = 1; i <= n; ++i) {
			int t, y, x;
			std::cin >> t >> xx >> y;
			x = xx / M;
			if (t == 1) {

			} else {

			}
		}
		std::
	}
	return 0;
}