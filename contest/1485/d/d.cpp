#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	const int lcm = 720720;
	for (int i = 0; i < n; ++i) {
		for (int j = 0, x; j < m; ++j) {
			std::cin >> x;
			if ((i + j) & 1) {
				std::cout << lcm + x * x * x * x << "\n";
			} else std::cout << lcm << "\n";
		}
	}
	return 0;
}