#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, M;
  std::cin >> n >> M;
  std::vector<int> pow2(n + 1, 1);
  for (int i = 1; i <= n; ++i) pow2[i] = pow2[i - 1] * 2 % M;
  std::vector<std::vector<int>> c(n + 1, std::vector<int>(n + 1));
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
    }
  }
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = pow2[i - 1];
    for (int j = 1; j * 2 < i; ++j) {
      for (int k = 2; k < i - 2 * (j - 1); ++k) {
        dp[i][j] = (dp[i][j] + 1LL * pow2[k - 2] * dp[i - k][j - 1] % M * c[i - j][k - 1]) % M;
      }
    }
  }
  std::cout << std::accumulate(dp[n].begin(), dp[n].end(), 0LL) % M << '\n';
  return 0;
}