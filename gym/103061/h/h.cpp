#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		int r = 0;
		std::vector<int> a;
		std::function<void(int)> add = [&](int x) {
			if (!a.empty() && a.back() == x) {
				++r;
				a.pop_back();
				add(1);
			} else a.emplace_back(x);
		};
		int i = 0, x = 0;
		while (i < n) {
			++i;
			std::cin >> x;
			if (x == 1) break;
			add(x);
		}
		if (!a.empty()) std::swap(a[0], a.back());
		if (x == 1) add(1);
		while (i < n) std::cin >> x, add(x), ++i;
		int z = std::count(a.begin(), a.end(), -1);
		if (z < a.size()) {
			if (z % 2 == 0) r += a.size() - z - 1;
			else {
				if (a[0] == -1 || a.back() == -1) {
					r += a.size() - z - 2;
				} else {
					r += a.size() - z - 4;
				}
			}
		}
		std::cout << r << '\n';
	}
	return 0;
}