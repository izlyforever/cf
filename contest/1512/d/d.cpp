#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2);
    for (auto& x : a) std::cin >> x;
    auto it = std::max_element(a.begin(), a.end());
    int mx = *it;
    a.erase(it);
    LL t = std::accumulate(a.begin(), a.end(), 0LL) - mx;
    if (auto ta = std::find(a.begin(), a.end(), t); ta != a.end()) {
      a.erase(ta);
      for (auto x : a) std::cout << x << ' ';
      std::cout << '\n';
    } else {
      auto it2 = std::max_element(a.begin(), a.end());
      int mx2 = *it2;
      a.erase(it2);
      if (std::accumulate(a.begin(), a.end(), 0LL) == mx2) {
        for (auto x : a) std::cout << x << ' ';
        std::cout << '\n';
      } else {
        std::cout << -1 << '\n';
      }
    }
  }
  return 0;
}