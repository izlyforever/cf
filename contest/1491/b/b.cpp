#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, u, v, r = INT_MAX;
    std::cin >> n >> u >> v;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    auto solve = [&](int i) {
      if (abs(a[i] - a[i - 1]) > 1) return 0;
      if (a[i] == a[i - 1]) return std::min(u + v, v * 2);
      return std::min(u, v);
    };
    for (int i = 1; i < n; ++i) r = std::min(r, solve(i));
    std::cout << r << "\n";
  }
  return 0;
}