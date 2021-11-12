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
    std::vector<std::pair<int, int>> r;
    int now = n;
    for (LL i = n - 1; i > 1; --i) {
      while (i <= (now + i - 1) / i) {
        now = (now + i - 1) / i;
        r.emplace_back(n, i);
      }
      r.emplace_back(i, n);
    }
    std::cout << r.size() << "\n";
    for (auto [x, y] : r) std::cout << x << " " << y << "\n";
  }
  return 0;
}