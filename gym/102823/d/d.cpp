#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  for (int T = 1; T <= cas; ++T) {
    LL x, y;
    std::cin >> x >> y;
    std::vector<int> a[2], b[2];
    int now = 0;
    while (x) {
      if (x & 1) {
        a[now & 1].emplace_back(now);
      }
      ++now;
      x >>= 1;
    }
    now = 0;
    while (y) {
      if (y & 1) {
        b[now & 1].emplace_back(now);
      }
      ++now;
      y >>= 1;
    }
    if (a[0].size() != b[0].size() || a[1].size() != b[1].size()) {
      std::cout << "Case " << T << ": -1\n";
    } else {
      int r = 0;
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
          r += abs(a[i][j] - b[i][j]);
        }
      }
      std::cout << "Case " << T << ": " << r / 2 << "\n";
    }
  }
  return 0;
}
