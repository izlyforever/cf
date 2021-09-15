#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using pll = std::pair<LL, LL>;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n = 4;
    std::vector<pll> a(n);
    for (auto& [x, y] : a) std::cin >> x >> y;
    LL ans = INT64_MAX;
    std::sort(a.begin(), a.end());
    do {
      LL sum = 0;
      // 0 3
      // 1 2
      sum += abs(a[0].first - a[1].first);
      sum += abs(a[2].first - a[3].first);
      sum += abs(a[0].second - a[3].second);
      sum += abs(a[1].second - a[2].second);
      LL xr = std::max(a[3].first, a[2].first) - std::min(a[1].first, a[0].first);
      LL xl = std::min(a[3].first, a[2].first) - std::max(a[1].first, a[0].first);
      LL yr = std::max(a[0].second, a[3].second) - std::min(a[1].second, a[2].second);
      LL yl = std::min(a[0].second, a[3].second) - std::max(a[1].second, a[2].second);
      ans = std::min(ans, sum + 2 * std::max(0LL, std::max(xl, yl) - std::min(xr, yr)));
    } while (std::next_permutation(a.begin(), a.end()));
    std::cout << ans << std::endl;
  }
  return 0;
}