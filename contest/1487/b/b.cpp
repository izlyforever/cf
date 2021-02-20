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
		if (n % 2 == 0) {
			std::cout << (k - 1) % n + 1 << "\n";
		} else {
			int n2 = n / 2;
			std::cout << (((k - 1) / n2) * (n2 + 1) + (k - 1) % n2) % n + 1 << "\n";
		}
	}
	return 0;
}