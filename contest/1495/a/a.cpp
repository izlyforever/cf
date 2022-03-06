#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  std::cout.precision(15);
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<LL> a, b;
    for (int i = 0; i < 2 * n; ++i) {
      LL x, y;
      std::cin >> x >> y;
      if (x == 0) {
        b.emplace_back(abs(y));
      } else {
        a.emplace_back(abs(x));
      }
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    double r = 0;
    for (int i = 0; i < n; ++i) {
      r += std::sqrt(a[i] * a[i] + b[i] * b[i]);
    }

    std::cout << std::fixed << r << "\n";
  }
  return 0;
}
