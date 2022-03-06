#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::set<int> dp[n + 1][m + 1];
  dp[1][1].insert(0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (auto x : dp[i][j - 1]) dp[i][j].insert(x + i);
      for (auto x : dp[i - 1][j]) dp[i][j].insert(x + j);
    }
  }
  return dp[n][m].find(k) != dp[n][m].end();
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
