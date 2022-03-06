#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> c(n), w(n);
  for (auto &x : c) std::cin >> x;
  for (auto &x : w) std::cin >> x;
  std::vector<std::vector<int>> e(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    e[v].emplace_back(u);
  }
  std::vector<int> isMul(n, -2);
  for (auto &x : c) ++isMul[--x];
  int mulSz = 0;
  for (auto &x : isMul) if (x > -1) x = mulSz++;
  std::vector<std::vector<int>> dp(n, std::vector<int>(1 << mulSz, 0));
  if (isMul[c[0]] != -1) {
    dp[0][1 << isMul[c[0]]] = w[c[0]];
  } else {
    dp[0][0] = w[c[0]];
  }
  for (int i = 1; i < n; ++i) {
    int ci = c[i];
    if (isMul[ci] == -1) {
      for (auto v : e[i]) {
        for (int j = 0; j < (1 << mulSz); ++j) {
          dp[i][j] = std::max(dp[i][j], dp[v][j] + w[ci]);
        }
      }
    } else {
      int bit = 1 << isMul[ci];
      for (auto v : e[i]) {
        for (int j = 0; j < (1 << mulSz); ++j) {
          dp[i][j] = std::max(dp[i][j], dp[v][j]);
          if ((j & bit) == 0) {
            dp[i][j | bit] = std::max(dp[i][j | bit], dp[v][j] + w[ci]);
          }
        }
      }
    }
  }
  for (const auto &x : dp) {
    std::cout << *std::max_element(x.begin(), x.end()) << '\n';
  }
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
