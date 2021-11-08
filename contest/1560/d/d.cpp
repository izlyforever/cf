#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int xx;
  std::cin >> xx;
  auto x = std::to_string(xx);
  std::vector<std::string> s(60);
  for (int i = 0; i < 60; ++i) s[i] = std::to_string(1LL << i);
  int ans = INT_MAX;
  for (const auto& y : s) {
    int n = x.size(), m = y.size(), i = 0, j = 0;
    while (j < m) {
      while (i < n && x[i] != y[j]) ++i;
      if (i == n) break;
      ++j;
      ++i;
    }
    ans = std::min(ans, n - j + m - j);
  }
  std::cout << ans << '\n';
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