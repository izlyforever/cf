#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> pos(n * n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      std::cin >> x;
      pos[--x] = {i, j};
    }
  }
  std::vector<std::string> ans(n, std::string(n, 'G'));
  int lp = INT_MIN, rp = INT_MIN, up = INT_MIN, dp = INT_MIN;
  for (int _ = n * n - 1; _ >= 0; --_) {
    auto [x, y] = pos[_];
    if (lp > k + x + y || rp > k + x - y || up > k - x + y || dp > k - x - y) {
      continue;
    }
    ans[x][y] = 'M';
    lp = std::max(lp, x + y);
    rp = std::max(rp, x - y);
    up = std::max(up, -x + y);
    dp = std::max(dp, -x - y);
  }
  for (auto &x : ans) std::cout << x << '\n';
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
