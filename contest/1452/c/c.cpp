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
    --n;
    LL s = 0, mx = 0, x;
    for (int i = 0; i <= n; ++i) {
      std::cin >> x;
      s += x;
      mx = std::max(mx, x);
    }
    mx = std::max(n * mx, s);
    mx = ((mx + n - 1) / n ) * n;
    std::cout << mx - s << std::endl;
  }
  return 0;
}