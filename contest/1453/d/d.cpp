#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL n;
    std::cin >> n;
    if (n & 1) {
      std::cout << -1 << std::endl;
      continue;
    }
    n /= 2;
    std::vector<int> a;
    while (n) {
      --n;
      int x = 1;
      while (n >> x) ++x;
      --x;
      n -= (1LL << x);
      a.emplace_back(1);
      for (int i = 1; i < x; ++i) a.emplace_back(0);
    }
    std::cout << a.size() << std::endl;
    for (auto x : a) std::cout << x << " ";
    std::cout << std::endl;
  }
  return 0;
}
