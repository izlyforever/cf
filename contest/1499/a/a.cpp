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
		int n, k1, k2, w, b;
		std::cin >> n >> k1 >> k2 >> w >> b;
		int a1 = std::min(k1, k2) + abs(k1 - k2) / 2;
		int a2 = std::min(n - k1, n - k2) + abs(k1 - k2) / 2;
		std::cout << (w <= a1 && b <= a2 ? "YES\n" : "NO\n");
	}
	return 0;
}