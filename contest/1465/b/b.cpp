#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	auto check = [](LL n) -> bool {
		int a[10]{};
		LL x = n;
		while (x) {
			++a[x % 10];
			x /= 10;
		}
		for (int i = 2; i < 10; ++i) if (a[i]) {
			if (n % i) return 0;
		}
		return 1;
	};
	while (cas--) {
		LL n;
		std::cin >> n;
		while (!check(n)) ++n;
		std::cout << n << std::endl;
	}
	return 0;
}