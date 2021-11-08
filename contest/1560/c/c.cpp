#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int x = std::sqrt(n - 1);
  int d = n - x * x;
  if (d <= x) {
    std::cout << d << ' ' << x + 1 << '\n';
  } else {
    std::cout << x + 1 << ' ' << 2 * x + 2 - d << '\n';
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}