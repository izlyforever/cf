
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int xa, ya, xb, yb, xf, yf;
  std::cin >> xa >> ya >> xb >> yb >> xf >> yf;
  int ans = abs(xa - xb) + abs(ya - yb);
  if (xa == xf && xb == xf) {
    auto [mi, mx] = std::minmax(ya, yb);
    if (mi < yf && yf < mx) ans += 2;
  } else if (ya == yf && yb == yf) {
    auto [mi, mx] = std::minmax(xa, xb);
    if (mi < xf && xf < mx) ans += 2;
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