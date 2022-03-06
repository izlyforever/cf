#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using pii = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<pii> a(n);
    for (auto& [x, y] : a) std::cin >> x >> y;
    auto check = [&](int i) {
      for (int j = 0; j < n; ++j) {
        if (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) > k) return false;
      }
      return true;
    };
    int r = -1;
    for (int i = 0; i < n; ++i) {
      if (check(i)) r = 1;
    }
    std::cout << r << std::endl;
  }
  return 0;
}
