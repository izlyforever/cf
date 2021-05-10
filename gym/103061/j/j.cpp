#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const int M = 998244353;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int> dp(n + 1);
	dp[2] = 1;
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 3] * 2;
		if (dp[i] >= M) dp[i] -= M;
		dp[i] += dp[i - 2];
		if (dp[i] >= M) dp[i] -= M;
	}
	std::cout << dp[n] << '\n';
	return 0;
}