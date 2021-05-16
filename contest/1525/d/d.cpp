#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	const int inf = 1e9 + 2;
	std::vector<int> a(n + 1), s(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	int last[2] {};
	std::vector<int> pre[2];
	pre[0].resize(n + 1);
	pre[1].resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		pre[0][i] = last[0];
		pre[0][i] = last[1];
		last[a[i]] = i;
	}
	std::vector<std::vector<int>> dp(n + 1);
	// dp[0] = {0};
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 0) {
			if (s[i] * 2 > i) {
				dp[i].emplace_back(inf);
				continue;	
			}
			int lst = pre[1][i];
			if (lst > 0) {
				dp[i].emplace_back(i - lst < dp[lst].size() ? dp[lst][i - lst] : dp[i].back());
			} else {
				dp[i].emplace_back(0);
			}
			int now = 0, l = pre[0][i];
			for (int j = i - l - 1; j < n; ++j) dp[i].emplace_back(++now + dp[l][j]);
		} else {
			int lst = pre[0][i];
			if (lst > 0) {
				dp[i].emplace_back(i - lst < dp[lst].size() ? dp[lst][i - lst] : inf);
			} else {
				dp[i].emplace_back(inf);
			}
			for (int j = 1; j < s[i] * 2 - i; ++j) dp[i].emplace_back(inf);
			
			int now = 0, l = pre[0][i];
			while (1) {
				int cur = inf;

			}
		}
	}
	std::cout << dp[n][0] << '\n';
	return 0;
}