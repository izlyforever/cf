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
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i].first;
    for (int i = 0; i < n; ++i) std::cin >> a[i].second;
    std::sort(a.begin(), a.end(), std::greater<>());
    int id = 0, now = 0, r = a[0].first;
    while (id < n && a[id].first >= now) {
      now += a[id].second;
      r = std::min(r, a[id].first);
      ++id;
    }
    std::cout << std::min(r, now) << std::endl;
  }
  return 0;
}
