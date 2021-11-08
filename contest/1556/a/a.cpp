#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int solve() {
  int x, y;
  std::cin >> x >> y;
  if ((x + y) & 1) return -1;
  if (x == 0 && y == 0) return 0;
  if (x == y) return 1;
  return 2;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}