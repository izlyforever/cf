#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		LL n;
		std::cin >> n;
		n /= n & (-n);
		std::cout << (n > 1 ? "YES\n" : "NO\n");
	}
	return 0;
}