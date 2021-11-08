#include <bits/stdc++.h>
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  if (n == 1) return false;
  int x = __builtin_ctz(n);
  if ((1 << x) != n) return !(n & 1);
  return !(x & 1);
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Alice" : "Bob") << '\n';
  }
  return 0;
}