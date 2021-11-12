#include <bits/stdc++.h>
using LL = long long;

// 模正数向下取整 和 向上取整
int floor(int a, int n) { // n > 0
  return a < 0 ? (a - n + 1) / n : a / n;
}
int ceil(int a, int n) { // n > 0
  return a < 0 ? a / n : (a + n - 1) / n;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int x, y, a, b;
    std::cin >> x >> y >> a >> b;
    if (a == b) {
      std::cout << std::min(x, y) / a << '\n';
    } else {
      if (a < b) std::swap(a, b);
      auto f = [&](int c) {
        int l = std::max(0, ceil(a * c - y, a - b));
        int r = std::min(c, floor(x - b * c, a - b));
        return l <= r;
      };
      int l = 0, r = (x + y) / (a + b);
      while (l <= r) {
        int m = (l + r) / 2;
        if (f(m)) l = m + 1;
        else r = m - 1;
      }
      std::cout << r << '\n';
    }
  }
  return 0;
}