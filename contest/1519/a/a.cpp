#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int r, b, d;
  std::cin >> r >> b >> d;
  // if (d == 0) return r == b;
  if (r < b) std::swap(r, b);
  return (r + d) / (d + 1) <= b;
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