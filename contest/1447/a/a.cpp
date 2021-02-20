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
		int n;
		std::cin >> n;
		std::cout << n - 1 << std::endl;
		for (int i = 2; i <= n; ++i) std::cout << i << " \n"[i == n];
	}
	return 0;
}