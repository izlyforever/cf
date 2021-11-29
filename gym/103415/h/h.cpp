#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  LL a, b, c;
  std::cin >> a >> b >> c;
  if (a == b && b == c) {
    if (a == 0) {
      std::cout << "YES\n";
      std::cout << "1 1 1\n";
    } else {
      std::cout << "NO\n";
    }
  } else {
    std::cout << "YES\n";
    LL x, y, z;
    if (a > c) {
      x = a;
      z = (b / a + 1) * a + c;
      y = 2 * z + b;
    } else if (c > b) {
      z = c;
      y = (a / c + 1) * c + b;
      x = 2 * y + a;
    } else {
      y = b;
      x = (c / b + 1) * b + a;
      z = 2 * x + c;
    }
    std::cout << x << ' ' << y << ' ' << z << '\n';
  }
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