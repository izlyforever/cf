#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    LL m, d, w;
    std::cin >> m >> d >> w;
    w = w / std::__gcd(d - 1, w);
    m = std::min(m, d);
    LL r = m / w;
    std::cout << (m - w) * r + (r - 1) * r / 2 * (-w) <<std::endl;
  }
  return 0;
}
