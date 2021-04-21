#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		for (int i = 0; k && i + 1 < n; ++i) {
			int now = std::min(a[i], k);
			a[i] -= now;
			k -= now;
			a.back() += now;
		}
		for (auto x : a) std::cout << x << ' ';
		std::cout << '\n';
	}
	return 0;
}