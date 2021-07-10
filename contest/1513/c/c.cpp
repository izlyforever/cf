#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	const int N = 2e5 + 12, M = 1e9 + 7;
	std::vector<std::array<int, 10>> dp(N);
	dp[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		dp[i][0] = dp[i - 1][9];
		for (int j = 1; j < 10; ++j) dp[i][j] = dp[i - 1][j - 1];
		dp[i][1] += dp[i - 1][9];
		if (dp[i][1] >= M) dp[i][1] -= M;
	}
	std::vector<int> ans(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 10; ++j) {
			ans[i] += dp[i][j];
			if (ans[i] >= M) ans[i] -= M;
		}
	}
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m, r = 0;
		std::cin >> n >> m;
		while (n) {
			r += ans[m + n % 10];
			if (r >= M) r -= M;
			n /= 10;
		}
		std::cout << r << '\n';
	}
	return 0;
}