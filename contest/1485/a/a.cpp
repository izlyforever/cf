#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	auto f = [](int a, int b) {
		int t = 0;
		while (a) {
			a /= b;
			++t;
		}
		return t;
	};
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int a, b, r = INT_MAX;
		std::cin >> a >> b;
		for (int i = std::max(2, b); i - b < r; ++i) {
			r = std::min(r, f(a, i) + i - b);
		}
		std::cout << r << "\n";
	}
	return 0;
}