#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL a[3], b[3];
    std::cin >> a[0] >> a[1] >> a[2];
    std::cin >> b[0] >> b[1] >> b[2];
    LL ans = 0;
    for (int i = 0; i < 3; ++i) {
      LL mn = std::min(a[i], b[(i + 1) % 3]);
      a[i] -= mn;
      b[(i + 1) % 3] -= mn;
      ans += mn;
    }
    for (int i = 0; i < 3; ++i) {
      LL mn = std::min(a[i], b[i]);
      a[i] -= mn;
      b[i] -= mn;
    }
    for (int i = 0; i < 3; ++i) {
      LL mn = std::min(b[i], a[(i + 1) % 3]);
      b[i] -= mn;
      a[(i + 1) % 3] -= mn;
      ans -= mn;
    }
    std::cout << ans << '\n';
  }
  return 0;
}
