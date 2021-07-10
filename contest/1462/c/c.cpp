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
		int r = 0, mx = 9, ten = 1;
		while (n) {
			if (n < mx) {
				r += ten * n;
				n = 0;
			} else {
				r += ten * mx;
				n -= mx;
				--mx;
			}
			ten *= 10;
			if (mx == 0) break;
		}
		std::cout << (n ? -1 : r) << std::endl;
	}
	return 0;
}