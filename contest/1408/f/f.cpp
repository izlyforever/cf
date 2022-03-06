#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> r;
  auto f = [&](int x, int len) {
    for (int step = 1; step < len; step *= 2) {
      for (int i = 0; i < len; i += step * 2) {
        for (int j = 0; j < step; ++j) {
          r.push_back({i + j + x, i + j + x + step});
        }
      }
    }
  };
  int k = std::__lg(n);
  f(1, 1 << k);
  f(n + 1 - (1 << k), 1 << k);
  print(r.size());
  for (auto [x, y] : r) std::cout << x << " " << y << std::endl;
  return 0;
}
