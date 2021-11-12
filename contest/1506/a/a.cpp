#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL n, m, x;
    std::cin >> n >> m >> x;
    --x;
    LL y = x / n + (x % n) * m;
    std::cout << ++y << '\n';
  }
  return 0;
}