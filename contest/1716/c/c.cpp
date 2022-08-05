#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
// 吐了

void solve() {
  int m;
  std::cin >> m;
  std::vector<std::vector<int>> a(2, std::vector<int>(m));
  auto dp = a;
  for (auto &ai : a) for (auto &x : ai) std::cin >> x;
  for (int i = 0; i < 2; ++i) {
    dp[i].back() = std::max(a[i].back() + 2, a[1 - i].back() + 1);
  }
  for (int j = m - 2; j >= 0; --j) {
    for (int i = 0; i < 2; ++i) {
      int x = std::max(a[i][j], a[i][j + 1]);
      dp[i][j] = std::max({x + (m - j) * 2, dp[i][j + 1] + 1, a[1 - i][j] + 1});
    }
  }
  for (int i = 0; i < 2; ++i) dp[i].emplace_back(0);
  int ans = dp[0][0] - 1, cur = 0;
  for (int i = 0, j = 0; j < m; ++j) {
    cur = std::max(cur, a[i][j]) + 1;
    int x = cur;
    if (j + 1 < m) x = std::max(x, a[i][j + 1]);
    ans = std::min(ans, std::max({x + (m - j) * 2 - 1, dp[i][j + 1] + 1, a[1 - i][j]}));
    i = 1 - i;
    cur = std::max(cur, a[i][j]) + 1;
  }
  // ans = std::min(ans, cur - 1);
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
