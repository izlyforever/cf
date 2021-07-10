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
		std::vector<int> a(2 * n + 1);
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			++a[x];
		}
		int r0 = 0, r1 = 0;
		int now = 0;
		for (int i = 1; i <= 2 * n; ++i) {
			if (a[i] == 0) ++now;
			else {
				if (now > 0) {
					++r0;
					--now;
				}
			}
		}
		now = 0;
		for (int i = 2 * n; i; --i) {
			if (a[i] == 0) ++now;
			else {
				if (now > 0) {
					++r1;
					--now;
				}
			}
		}
		std::cout << abs(r0 - (n - r1)) + 1 << std::endl;
	}
	return 0;
}