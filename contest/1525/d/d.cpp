#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pos;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    if (a[i]) pos.emplace_back(i);
  }
  int k = pos.size();
  const int inf = 1e9 + 2;
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, inf));
  for (int i = 0; i <= n; ++i) dp[i][0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 0;
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (a[i] == 0) dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + abs(pos[j - 1] - i));
    }
  }
  std::cout << dp[n][k] << '\n';
  return 0;
}
