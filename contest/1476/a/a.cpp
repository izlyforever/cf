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
		if (n >= k) {
			std::cout << (n % k == 0 ? 1 : 2) << "\n";
		} else {
			std::cout << (k + n - 1) / n << "\n";
		}
	}
	return 0;
}