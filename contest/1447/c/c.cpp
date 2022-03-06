#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    LL w;
    std::cin >> n >> w;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i].first;
      a[i].second = i + 1;
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    std::vector<int> x;
    bool flag = false;
    LL s = 0, h = (w + 1) / 2;
    for (int i = 0; i < n; ++i) {
      if (s + a[i].first <= w) {
        x.emplace_back(a[i].second);
        s += a[i].first;
        if (s >= h) {
          flag = true;
          break;
        }
      }
    }
    if (flag) {
      std::sort(x.begin(), x.end());
      std::cout << x.size() << std::endl;
      for (auto i : x) std::cout << i << " ";
      std::cout << std::endl;
    } else std::cout << -1 << std::endl;
  }
  return 0;
}
