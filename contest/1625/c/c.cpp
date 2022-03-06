#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void cmin(int &x, int y) {
  x = std::min(x, y);
}

void solve() {
  int n, l, cnt;
  std::cin >> n >> l >> cnt;
  std::vector<int> d(n), a(n);
  for (auto &x : d) std::cin >> x;
  d.emplace_back(l);
  for (auto &x : a) std::cin >> x;
  std::vector<std::vector<int>> dp(n + 1);
  for (int i = 1; i <= n; ++i) dp[i] = std::vector<int>(i, 1e9);
  for (int i = 1; i <= n; ++i) {
    auto& dpi = dp[i];
    dpi[i - 1] = (d[i] - d[0]) * a[0];
    for (int j = 1; j < i; ++j) {
      for (int k = 0; k < j; ++k) {
        cmin(dpi[i - j - 1 + k], dp[j][k] + (d[i] - d[j]) * a[j]);
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i <= cnt; ++i) cmin(ans, dp[n][i]);
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
