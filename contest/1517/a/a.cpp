#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL n;
    std::cin >> n;
    if (n % 2050) {
      std::cout << -1 << '\n';
    } else {
      n /= 2050;
      int r = 0;
      while (n) {
        r += n % 10;
        n /= 10;
      }
      std::cout << r << '\n';
    }
  }
  return 0;
}
