#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		LL x;
		std::cin >> x;
		auto f = [](int n) -> LL {
			LL x = 1LL << n;
			return 2 * (x * x - 1) / 3 - x + 1;
		};
		int l = 0, r = 30;
		while (l <= r) {
			int m = (l + r) / 2;
			if (f(m) > x) r = m - 1;
			else l = m + 1;
		}
		print(r);
	}
	return 0;
}