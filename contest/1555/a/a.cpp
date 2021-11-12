#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  LL n;
  std::cin >> n;
  if (n & 1) ++n;
  if (n <= 6) std::cout << 15 << '\n';
  else std::cout << n * 5 / 2 << '\n';
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