#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, r = 0;
    std::cin >> n;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      if (x == 2) ++r;
    }
    std::cout << n - r << '\n';
  }
  return 0;
}