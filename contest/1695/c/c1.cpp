#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
using vi = std::vector<int>;

bool solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<vi> mn(n + 1, vi(m + 1, INT_MAX));
  std::vector<vi> mx(n + 1, vi(m + 1, INT_MIN));
  mx[0][1] = mn[0][1] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x;
      std::cin >> x;
      mx[i][j] = std::max(mx[i - 1][j], mx[i][j - 1]) + x;
      mn[i][j] = std::min(mn[i - 1][j], mn[i][j - 1]) + x;
    }
  }
  return ((n + m) & 1) && mx[n][m] >= 0 && mn[n][m] <= 0;
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
