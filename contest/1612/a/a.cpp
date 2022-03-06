#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int x, y;
  std::cin >> x >> y;
  if ((x + y) & 1) {
    std::cout << "-1 -1\n";
  } else {
    std::cout << x / 2 << ' ' << (y + 1) / 2 << '\n';
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
