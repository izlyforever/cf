#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  LL x;
  std::cin >> x;
  for (LL i = 1; i * i * i * 2 <= x; ++i) {
    LL j = std::cbrt(x - i * i * i + 0.1);
    if (i * i * i + j * j * j == x) return true;
  }
  return false;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}
