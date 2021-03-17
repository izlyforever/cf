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
		int n, k;
		std::cin >> n >> k;
		int x = n & -n;
		if (x == n) {
			std::cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << '\n';
		} else {
			std::cout << x << ' ' << (n - x) / 2 << ' ' << (n - x) / 2 << '\n';
		}
	}
	return 0;
}