#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const int M = 1e9 + 7;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	std::vector<LL> dp(n + 1, 1), newDp(n + 1), ans(k + 1);
	LL s[2]{1, 0};
	for (int j = 1; j <= k; ++j) {
		newDp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			newDp[i] = (newDp[i - 1] + dp[i - 1] * (i - 1)) % M;
		}
		std::swap(dp, newDp);
		if ((s[j & 1] += dp[n]) >= M) s[j & 1] -= M;
		ans[j] = s[j & 1];
	}
	for (int i = 1; i <= k; ++i) std::cout << ans[i] << " \n"[i == k];
	return 0;
}