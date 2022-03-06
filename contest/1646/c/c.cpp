#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const LL N = 1e12 + 2;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<LL> a;
  LL cur = 6;
  for (int i = 4; cur < N; ++i) {
    a.emplace_back(cur);
    cur *= i;
  }
  int sa = a.size();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL n;
    std::cin >> n;
    int ans = 63;
    for (int i = 0; i < (1 << sa); ++i) {
      LL tmp = 0;
      for (int j = 0; j < sa; ++j) {
        if (i & (1 << j)) tmp += a[j];
      }
      if (n >= tmp) {
        ans = std::min(ans, __builtin_popcount(i) + __builtin_popcountll(n - tmp));
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
