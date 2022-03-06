#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL n, m, k;
    std::cin >> n >> m >> k;
    LL y = k / (n * 2) * 2, x = 0;
    k %= (n * 2);
    if (k >= n) {
      x = (2 * n - 1) - k;
      ++y;
    } else {
      x = k;
    }
    std::cout << (x + y) << '\n';
  }
  return 0;
}
