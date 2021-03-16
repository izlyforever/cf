#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, x;
		std::cin >> n >> x;
		int s = 0;
		bool f1 = 0, f2 = 0;
		for (int i = 0, t; i < n; ++i) {
			std::cin >> t;
			if (t == x) f1 = 1;
			else f2 = 1;
			s += t;
		}
		if (f2 == 0) {
			print(0);
		} else if (f1 == 1 || x * n == s) {
			print(1);
		} else print(2);
	}
	return 0;
}