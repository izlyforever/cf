#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, d;
		std::cin >> n >> d;
		auto f = [&](int x) {
			if (x >= d * 10) return 1;
			for (int i = d; i <= x; i += d) {
				if ((x - i) % 10 == 0) return 1;
			}
			return 0;
		};
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			std::cout << (f(x) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}