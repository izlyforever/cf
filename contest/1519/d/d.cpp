#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<LL> a(n), b(n);
	for (auto &x : a) std::cin >> x;
	for (auto &x : b) std::cin >> x;
	// dp[i][j] 表示扭转了 [i, j] 区间后的差值
	std::vector<std::vector<LL>> dp(n, std::vector<LL>(n));
	LL ans = 0;
	for (int len = 1; len < n; ++len) {
		for (int i = 0, j = i + len; j < n; ++i, ++j) {
			dp[i][j] = (a[j] - a[i]) * (b[i] - b[j]) + dp[i + 1][j - 1];
			ans = std::max(ans, dp[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) ans += a[i] * b[i];
	std::cout << ans << '\n';
	return 0;
}