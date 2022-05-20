#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
// int x = a + i y > c
  int y = b;
  int z = c;
  int x = ((c - a) / y + 1) * y + a;
  std::cout << x << ' ' << y << ' ' << z << '\n';

  assert(x % y == a);
  assert(y % z == b);
  assert(z % x == c);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
