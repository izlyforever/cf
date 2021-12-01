#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

char solve() {
  int x1, p1;
  std::cin >> x1 >> p1;
  int x2, p2;
  std::cin >> x2 >> p2;
  if (p1 > p2) {
    p1 -= p2;
    while (p1--) {
      x1 *= 10;
      if (x1 > x2) return '>';
    }
    return x1 == x2 ? '=' : '<';
  } else {
    p2 -= p1;
    while (p2--) {
      x2 *= 10;
      if (x1 < x2) return '<';
    }
    if (x1 < x2) return '<';
    return x1 == x2 ? '=' : '>';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}