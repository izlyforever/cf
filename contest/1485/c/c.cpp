#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// a / b = a - (a / b) * b
// a = (a / b) * (b + 1)
// a = (b + 1) n, 0 < n < b
// fixed b, \sum_{b = 2}^y min(x / (b + 1), b - 1)
// \sum_{i = 3}^{y + 1} min(x / i, i - 2)


int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL x, y;
    std::cin >> x >> y;
    LL r = 0, b = 3;
    ++y;
    while (b <= y && b * (b - 2) <= x) {
      r += b - 2;
      ++b;
    }
    y = std::min(x, y);
    for (LL j; b <= y; b = j + 1) {
      j = std::min(y, x / (x / b));
      r += (x / b) * (j - b + 1);
    }
    std::cout << r << "\n";
  }
  return 0;
}