#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (auto &x : p) std::cin >> x;
  for (auto &x : p) --x;
  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  {
    std::vector<int> now(n);
    for (int i = 0; i < n; ++i) {
      for (int j = p[i]; j < n; ++j) ++now[j];
      for (int j = 0; j < n; ++j) {
        a[i][j] = now[j];
      }
    }
  }
  std::vector<std::vector<int>> b(n, std::vector<int>(n));
  {
    std::vector<int> now(n);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = p[i]; j < n; ++j) ++now[j];
      for (int j = 0; j < n; ++j) {
        b[i][j] = now[j];
      }
    }
  }
  LL ans = 0;
  for (int i = 1; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      ans += a[i - 1][p[j]] * b[j + 1][p[i]];
    }
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
