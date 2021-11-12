#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> c(3, -n / 3);
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      ++c[x % 3];
    }
    auto check = [&]() {
      return c[0] || c[1] || c[2];
    };
    int r = 0, i = 0;
    while (check()) {
      if (c[i] > 0) {
        c[(i + 1) % 3] += c[i];
        r += c[i];
        c[i] = 0;
      }
      (++i) %= 3;
    }
    std::cout << r << "\n";
  }
  return 0;
}