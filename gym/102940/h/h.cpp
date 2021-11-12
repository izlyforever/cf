#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int M = 1e9 + 7;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> factor(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) factor[j].emplace_back(i);
  }
  std::vector<std::vector<int>> dp(k, std::vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) dp[0][i] = 1;
  for (int i = 1; i < k; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int t : factor[j]) {
        (dp[i][j] += dp[i - 1][t]) %= M;
      }
    }
  }
  int r = 0;
  for (int i = 1; i <= n; ++i) (r += dp[k - 1][i]) %= M;
  std::cout << r << std::endl;
  return 0;
}