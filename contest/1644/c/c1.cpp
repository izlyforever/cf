#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n + 1), b(n + 1, INT_MIN);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  std::vector<int> ans(n + 1);
  for (int step = 1; step <= n; ++step) {
    for (int i = step; i <= n; ++i) {
      b[step] = std::max(b[step], a[i] - a[i - step]);
    }
    for (int i = 0; i <= step; ++i) {
      ans[i] = std::max(ans[i], b[step] + i * x);
    }
  }
  for (int i = 1; i <= n; ++i) ans[i] = std::max(ans[i], ans[i - 1]);
  for (int i = 0; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
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
