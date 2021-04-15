// 下面代码不能被向量化，因此加下面优化也没啥用
// #ifdef ONLINE_JUDGE
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
// #endif

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
	for (int i = 0; i < n; ++i) {
		int mx = INT_MAX, my = INT_MAX;
		for (int j = i; j < n; ++j) {
			mx = std::min(mx, x[j]);
			my = std::min(my, y[j]);
			// LL t = LL(mx) * my;
			// if (t * (n - i) < ans) break;
			ans = std::max(ans, LL(j - i + 1) * mx * my);
		}
	}
	std::cout << ans << '\n';
	return 0;
}