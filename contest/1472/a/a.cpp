#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int w, h, n;
    std::cin >> w >> h >> n;
    auto f = [](int x) {
      int r = 1;
      while (x % 2 == 0) {
        x /= 2;
        r *= 2;
      }
      return r;
    };
    std::cout << (f(w) * f(h) >= n ? "YES" : "NO") << std::endl;
  }
  return 0;
}