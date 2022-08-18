#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  LL x = 1LL * a * d;
  LL y = 1LL * b * c;
  if (x == y) return 0;
  if (x == 0 || y == 0 || x % y == 0 || y % x == 0) return 1;
  return 2;
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
