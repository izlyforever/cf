#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 502;
std::vector<std::tuple<int, int, int>> dir[N][N];
int dp[12][N][N];

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 1, x; j < m; ++j) {
      std::cin >> x;
      x *= 2;
      dir[i][j].emplace_back(x, i, j - 1);
      dir[i][j - 1].emplace_back(x, i, j);
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0, x; j < m; ++j) {
      std::cin >> x;
      x *= 2;
      dir[i][j].emplace_back(x, i - 1, j);
      dir[i - 1][j].emplace_back(x, i, j);
    }
  }
  if (k % 2) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cout << -1 << " \n"[j == m - 1];
      }
    }
    return 0;
  }
  k /= 2;
  for (int t = 1; t <= k; ++t) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp[t][i][j] = INT_MAX;
        for (auto [x, xi, xj] : dir[i][j]) {
          dp[t][i][j] = std::min(dp[t][i][j], dp[t - 1][xi][xj] + x);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cout << dp[k][i][j] << " \n"[j == m - 1];
    }
  }
  return 0;
}