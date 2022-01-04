#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  auto b = a, c = a, d = a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
    for (int j = 0; j < n; ++j) {
      std::cin >> b[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> c[i][j];
    }
    for (int j = 0; j < n; ++j) {
      std::cin >> d[i][j];
    }
  }
  LL ans = std::min({b[0][0], b[0].back(), b.back()[0], b.back().back(), c[0][0], c[0].back(), c.back()[0], c.back().back()});
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans += d[i][j];
    }
  }
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