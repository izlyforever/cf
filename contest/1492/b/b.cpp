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
		std::vector<int> a(n), b(n), c;
		for (auto &x : a) std::cin >> x;
		int now = 0;
		for (int i = 0; i < n; ++i) {
			now = std::max(now, a[i]);
			b[i] = now;
		}
		int last = n;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] == b[i]) {
				for (int j = i; j < last; ++j) {
					c.emplace_back(a[j]);
				}
				last = i;
			}
		}
		for (auto &x : c) std::cout << x << " ";
		std::cout << "\n";
	}
	return 0;
}