#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int w, h;
  std::cin >> w >> h;
  LL ans = 0;
  for (int _ = 0; _ < 2; ++_) {
    int k;
    std::cin >> k;
    int x, y;
    std::cin >> x;
    for (int i = 1; i < k; ++i) std::cin >> y;
    ans = std::max(ans, 1LL * (y - x) * h);
  }
  for (int _ = 0; _ < 2; ++_) {
    int k;
    std::cin >> k;
    int x, y;
    std::cin >> x;
    for (int i = 1; i < k; ++i) std::cin >> y;
    ans = std::max(ans, 1LL * (y - x) * w);
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
