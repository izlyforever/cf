#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int k;
    std::cin >> k;
    std::cout << 100 / std::gcd(k, 100 - k) << '\n';
  }
  return 0;
}