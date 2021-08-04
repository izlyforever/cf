#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    if (n == 2) {
      std::cout << "-1\n";
      continue;
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    int now = 0;
    for (int i = 0; i < n; ++i) dp[i][i] = ++now;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; i + j < n; ++j) {
        dp[i+ j][j] = ++now;
      }
      for (int j = 0; i + j < n; ++j) {
        dp[j][i + j] = ++now;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << dp[i][j] << " \n"[j == n - 1];
      }
    }
  }
  return 0;
}