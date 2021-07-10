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
		std::vector<std::pair<int, int>> a(n);
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			a[i] = {x, i + 1};
		}
		std::sort(a.begin(), a.end());
		LL now = 0;
		std::vector<LL> b(n);
		for (int i = 0; i < n; ++i) {
			now += a[i].first;
			b[i] = now;
		}
		std::vector<int> c{a[n - 1].second};
		for (int i = n - 2; i >= 0 && b[i] >= a[i + 1].first; --i) {
			c.emplace_back(a[i].second);
		}
		std::sort(c.begin(), c.end());
		std::cout << c.size() << "\n";
		for (auto x : c) std::cout << x << " ";
		std::cout << "\n";
	}
	return 0;
}