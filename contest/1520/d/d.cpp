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
    std::map<int, int> mp;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      ++mp[x - i];
    }
    LL r = 0;
    for (auto [x, c] : mp) {
      r += 1LL * c * (c - 1) / 2;
    }
    std::cout << r << '\n';
  }
  return 0;
}