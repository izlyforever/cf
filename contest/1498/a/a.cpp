#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  auto f = [](LL n) {
    LL r = 0;
    while (n) {
      r += n % 10;
      n /= 10;
    }
    return r;
  };
  while (cas--) {
    LL n;
    std::cin >> n;
    while (std::gcd(n, f(n)) == 1) ++n;
    std::cout << n << '\n';
  }
  return 0;
}
