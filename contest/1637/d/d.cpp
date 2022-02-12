#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// cost = (\sum a)^ 2

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), c(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  int pre = 0;
  for (int i = 0; i < n; ++i) {
    auto [x, y] = std::minmax(a[i], b[i]);
    pre += x;
    c[i] = y - x;
  }
  int sc = std::accumulate(c.begin(), c.end(), 0);
  int m = sc / 2;
  std::vector<int> f(m + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= c[i]; --j) {
      f[j] = std::max(f[j], f[j - c[i]] + c[i]);
    }
  }
  int x = f[m] + pre, y = sc - f[m] + pre;
  int sa = 0, sb = 0;
  for (auto &x : a) sa += x * x;
  for (auto &x : b) sb += x * x;
  std::cout << x * x + y * y + (sa + sb) * (n - 2) << '\n';
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