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
		int x, y;
		std::cin >> x >> y;
		if (x < y) std::swap(x, y);
		y = std::max(y, x - 1);
		std::cout << x + y << std::endl;
	}
	return 0;
}