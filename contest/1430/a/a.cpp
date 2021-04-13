#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		auto f = [](int n) -> std::tuple<int, int, int> {
			int x3 = 0, x5 = 0, x7 = 0;
			for (x3 = 0; 3 * x3 <= n; ++x3) {
				for (x5 = 0; 3 * x3 + 5 * x5 <= n; ++x5) {
					if ((n - 3 * x3 - 5 * x5) % 7 == 0) {
						x7 = (n - 3 * x3 - 5 * x5) / 7;
						return {x3, x5, x7};
					}
				}
			}
			return {x3, x5, x7};
		};
		auto [x3, x5, x7] = f(n);
		if (3 * x3 + 5 * x5 + 7 * x7 == n) {
			std::cout << x3 << " " << x5 << " " << x7 << std::endl;
		} else print(-1);
	}
	return 0;
}