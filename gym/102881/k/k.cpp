#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  freopen("plants.in","r",stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> h(n), g(n);
  for (auto& x : h) std::cin >> x;
  for (auto& x : g) std::cin >> x;
  std::cout << [&]() -> int {
    int l = 0, r = INT_MAX;
    for (int i = 0; i + 1 < n; ++i) {
      if (h[i] <= h[i + 1]) {
        if (g[i] > g[i + 1]) r = std::min(r, (h[i + 1] - h[i])/ (g[i] - g[i + 1]));
      } else {
        if (g[i] >= g[i + 1]) return -1;
        l = std::max(l, (h[i] - h[i + 1] + g[i + 1] - g[i] - 1)/ (g[i + 1] - g[i]));
      }
      if (l > r) return -1;
    }
    return l;
  }() << std::endl;
  return 0;
}