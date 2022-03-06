#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int x, y;
    std::cin >> x >> y;
    if (x < y) std::swap(x, y);
    y = std::max(y, x - 1);
    std::cout << x + y << std::endl;
  }
  return 0;
}
