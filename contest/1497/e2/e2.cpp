#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e7 + 2;
  std::vector<int> f(N), mp(N);
  for (int i = 1; i * i < N; ++i) {
    int ii = i * i, cur = 0;
    for (int j = ii; j < N; j += ii) f[j] = ++cur;
  }
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a) {
      std::cin >> x;
      x = f[x];
    }
    std::vector<std::vector<int>> left(n, std::vector<int>(k + 1));
    for (int j = 0; j <= k; ++j) {
      int cnt = 0, now = 0;
      for (int i = 0; i < n; ++i) {
        if (++mp[a[i]] > 1) {
          if (++cnt > j) {
            while (--mp[a[now]] == 0) ++now;
            ++now;
            --cnt;
          }
        }
        left[i][j] = now;
      }
      for (int i = now; i < n; ++i) --mp[a[i]];
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, n));
    for (int j = 0; j <= k; ++j) dp[0][j] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        for (int x = 0; x <= j; ++x) {
          dp[i][j] = std::min(dp[i][j], left[i][x] > 0 ? dp[left[i][x] - 1][j - x] + 1 : 1);
        }
      }
    }
    std::cout << dp[n - 1][k] << '\n';
  }
  return 0;
}