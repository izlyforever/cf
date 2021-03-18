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
		auto f = [&](std::vector<LL> &a) -> std::vector<LL> {
			int sz = a.size();
			std::vector<LL> b(sz);
			LL sm = 0, mn = INT64_MAX;
			for (int i = 0; i < sz; ++i) {
				sm += a[i];
				mn = std::min(mn, a[i]);
				b[i] = sm + mn * (n - 1 - i);
			}
			return b;
		};
		std::vector<LL> a[2];
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			a[i & 1].emplace_back(x);
		}
		std::vector<LL> sa[2] = {f(a[0]), f(a[1])};
		LL r = INT64_MAX;
		for (int i = 1; i < n; ++i) {
			r = std::min(r, sa[0][i / 2] + sa[1][(i - 1) / 2]);
		}
		std::cout << r << '\n';
	}
	return 0;
}