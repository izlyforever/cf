#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
  }
  std::cout.precision(12);
  std::cout << std::fixed << 1.0 / n << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}