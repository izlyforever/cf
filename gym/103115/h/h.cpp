#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, v1, v2, x1, x2;
    std::cin >> n >> v1 >> v2 >> x1 >> x2;
    if (x1 < x2) {
      x1 = n - x1;
      x2 = n - x2;
    } else {
      --x1;
      --x2;
    }
    int ans = 0;
    while (1) {
      ++ans;
      if (x2 == 0 && x1 == 1) break;
      x2 -= v2;
      if (x2 < 0) x2 &= 1;
      ++ans;
      x1 -= v1;
      if (x1 <= x2) break;
    }
    std::cout << ans << '\n';
  }
  return 0;
}