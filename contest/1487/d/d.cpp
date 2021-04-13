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
		int x = std::sqrt(2 * n - 0.9);
		if (x % 2 == 0) --x;
		std::cout << (x < 3 ? 0 : (x - 3) / 2 + 1) << "\n";
	}
	return 0;
}