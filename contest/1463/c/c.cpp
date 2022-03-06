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
    std::vector<std::pair<LL, LL>> a(n);
    for (auto& [t, x] : a) std::cin >> t >> x;
    a.emplace_back(INT64_MAX, 0);
    LL t = a[0].first, x0 = 0, x1 = a[0].second;
    int now = 0, r = 0;
    while (now < n) {
      LL dt = abs(x0 - x1);
      if (dt == 0) {
        ++r;
        ++now;
      } else {
        while (now < n && a[now].first < t + dt) {
          LL tmp = abs(a[now].second - x0);
          if ((a[now].second - x0) * (x1 - x0) >= 0 && dt >= tmp && a[now].first - t <= tmp && a[now + 1].first - t >= tmp) ++r;
          ++now;
        }
      }
      x0 = x1;
      t = a[now].first;
      x1 = a[now].second;
    }
    std::cout << r << std::endl;
  }
  return 0;
}
