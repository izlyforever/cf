#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m ,k;
	std::cin >> n >> m >> k;
	auto cmax = [](int &x, int y) {
		if (x < y) x = y;
	};
	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(k, -1e9));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		std::vector<int> a(m);
		for (auto &x : a) std::cin >> x;
		for (int j = 0; j < m; ++j) {
			for (int cnt = m; cnt >= 1; --cnt) {
				for (int _ = 0; _ < k; ++_) {
					cmax(dp[cnt][(a[j] + _) % k], dp[cnt - 1][_] + a[j]);
				}
			}
		}
		for (int cnt = 1; cnt * 2 <= m; ++cnt) {
			for (int _ = 0; _ < k; ++_) {
				cmax(dp[0][_], dp[cnt][_]);
				dp[cnt][_] = -1e9;
			}
		}
	}
	print(dp[0][0]);
	return 0;
}