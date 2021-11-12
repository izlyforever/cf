#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int u, v;
  std::cin >> u >> v;
  if (u > v) return 0;
  int x = 0, y = 0;
  for (int i = 0; i < 30; ++i) {
    x += u % 2;
    y += v % 2;
    u /= 2;
    v /= 2;
    if (x < y) return 0;
  }
  return 1;
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