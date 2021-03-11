#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	if (k == 0) {
		std::cout << "-1\n";
	} else {
		for (int i = 1; i <= k; ++i) {
			std::cout << i % k + 1 << " \n"[i == n];
		}
		for (int i = k + 1; i <= n; ++i) {
			std::cout << i << " \n"[i == n];
		}
	}
	return 0;
}