#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  std::vector<std::vector<LL>> dp(n, std::vector<LL>(n));
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j + i < n; ++j) {
      dp[j][i + j] = std::min(dp[j + 1][i + j], dp[j][i + j - 1]) + a[i + j] - a[j];
    }
  }
  std::cout << dp[0][n - 1] << '\n';
  return 0;
}