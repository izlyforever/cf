#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

bool solve() {
  LL a, b, x;
  std::cin >> a >> b >> x;
  if (x == a || x == b) return true;
  while (a > x || b > x) {
    while (a >= b) {
      a -= b;
      b = abs(a - b);
      if (x == a || x == b) return true;
    }
    if (a == 0 || (a < x && b < x)) return false;
    LL mul = b / a, c = b - mul * a;
    if ((x - c) % a == 0) return true;
    mul %= 3;
    if (mul == 0) {
      b = c;
    } else {
      LL tmp = (mul - 1) * a + c;
      b = abs((mul - 2) * a + c);
      a = tmp;
    }
    if (x == a || x == b) return true;
  }
  return false;
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