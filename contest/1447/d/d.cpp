#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	std::string a, b;
	std::cin >> n >> m >> a >> b;
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
	int r = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = std::max({0, dp[i - 1][j] - 1, dp[i][j - 1] - 1});
			if (a[i - 1] == b[j - 1]) dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 2);
			r = std::max(r, dp[i][j]);
		}
	}
	std::cout << r << std::endl;
	return 0;
}