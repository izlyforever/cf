#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int N = 4002;
using Node = std::bitset<N>;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Node> dp(m + 1);
  dp[1][n + m] = 1;
  for (int i = 1; i <= n; ++i) {
    std::vector<Node> pd(m + 1);
    Node now;
    for (int j = 1; j <= m; ++j) {
      now |= dp[j];
      int x;
      std::cin >> x;
      if (x == 1) {
        now <<= 1;
      } else {
        now >>= 1;
      }
      pd[j] = now;
    }
    std::swap(dp, pd);
  }
  std::cout << (dp[m][n + m] ? "YES" : "NO") << '\n';
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
