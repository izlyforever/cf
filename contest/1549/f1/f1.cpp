#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
// Pick's theorem

void solve() {
  int n;
  std::cin >> n;
  int cnt[2][2]{};
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    x = (x % 4 != 0);
    y = (y % 4 != 0);
    ++cnt[x][y];
  }
  auto C = [](int n, int k) -> LL {
    if (k == 0) return 1;
    if (k == 1) return n;
    if (k == 2) return 1LL * n * (n - 1) / 2;
    return 1LL * n * (n - 1) * (n - 2) / 6;
  };
  LL ans = 0;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      ans += C(cnt[i][j], 3);
      for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) if (i != k || j != l) {
          ans += C(cnt[i][j], 2) * C(cnt[k][l], 1);
        }
      }
    }
  }
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
