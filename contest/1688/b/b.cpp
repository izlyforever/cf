#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  int mx = 32;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    int bx = __builtin_ctz(x);
    if (bx) ++ans;
    mx = std::min(mx, bx);
  }
  ans += std::max(mx - 1, 0);
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
