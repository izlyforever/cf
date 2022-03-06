#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const LL M = 1000003;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto& x : a) std::cin >> x;
  std::vector<std::vector<LL>> dp(n, std::vector<LL>(n)), val(n, std::vector<LL>(n));
  for (int i = 0; i < n; ++i) {
    LL now = 1;
    for (int j = i; j < n; ++j) {
      val[i][j] = now = now * a[j] % M;
    }
  }
  for (int len = 1; len < n; ++len) {
    for (int i = 0; i + len < n; ++i) {
      for (int k = 0; k < len; ++k) {
        LL tmp = val[i][i + k] - val[i + k + 1][i + len];
        dp[i][i + len] = std::max(dp[i][i + len], dp[i][i + k] + dp[i + k + 1][i + len] + tmp * tmp);
      }
    }
  }
  std::cout << dp[0][n - 1] << '\n';
  return 0;
}
