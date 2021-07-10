#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	auto f = [](int x, int y) {
		if (x < y) std::swap(x, y);
		int r = 0;
		while (x > 2 * y) {
			x = (x + 1) / 2;
			++r;
		}
		return r;
	};
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		int r = 0;
		for (int i = 1; i < n; ++i) {
			r += f(a[i - 1], a[i]);
		}
		std::cout << r << "\n";
	}
	return 0;
}