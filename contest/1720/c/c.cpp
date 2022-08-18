#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (auto &x : a) std::cin >> x;
  auto f = [](char x) { return x - '0';};
  int mx = 4;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      mx = std::min(mx, f(a[i - 1][j - 1] + f(a[i][j - 1]) + f(a[i - 1][j]) + f(a[i][j])));
    }
  }
  int ans = 0;
  for (auto &x : a) ans += std::count(x.begin(), x.end(), '1');
  std::cout << ans - std::max(0, (mx - 2)) << '\n';
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
