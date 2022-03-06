#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m, x1, y1, x2, y2;
  std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  int ans = 2 * std::max(n, m);
  if (x1 <= x2) {
    ans = std::min(ans, x2 - x1);
  } else {
    ans = std::min(ans, n - x1 + n - x2);
  }
  if (y1 <= y2) {
    ans = std::min(ans, y2 - y1);
  } else {
    ans = std::min(ans, m - y1 + m - y2);
  }
  std::cout << ans << '\n';
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
