#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int l, r, k;
  std::cin >> l >> r >> k;
  if (r == l) return l != 1;
  if (l % 2 == 0) ++l;
  if (r % 2 == 0) --r;
  return (r - l) / 2 + 1 <= k;
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