#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];
	LL ans = 0;
	std::function<void(int, int)> diviedConqer = [&](int l, int r) {
		if (r - l == 1) {
			ans = std::max(ans, LL(x[l]) * y[l]);
		} else {
			int m = (l + r) / 2;
			diviedConqer(l, m);
			diviedConqer(m, r);			
			// 分四种情况，咋变成 O(n) 呢
			
		}
	};
	return 0;
}