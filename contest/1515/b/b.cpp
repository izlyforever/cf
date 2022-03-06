#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int x;
  std::cin >> x;
  if (x & 1) return 0;
  int sx = std::sqrt(x);
  if (sx * sx == x) return 1;
  x /= 2;
  sx = std::sqrt(x);
  return sx * sx == x;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
