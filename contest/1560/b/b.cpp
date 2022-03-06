#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a > b) std::swap(a, b);
  int d = b - a;
  if (d < a) return -1;
  int n = 2 * d;
  if (c > n) return -1;
  return c > d ? c - d : c + d;
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
