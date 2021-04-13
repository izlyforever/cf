#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m, k;
		std::cin >> n >> m >> k;
		LL x = n - 2 - LL(m - 1) * (k - 1);
		auto f = [](int x) {
			int r = 0;
			while (x) {
				x /= 2;
				r += x;
			}
			return r;
		};
		m -= 2;
		if (m > x) {
			std::cout << "NO" << std::endl;
		} else if (m == x) {
			std::cout << "YES" << std::endl;
		} else std::cout << (f(m) + f(x - m) == f(x) ? "YES" : "NO") << std::endl;
	}
	return 0;
}