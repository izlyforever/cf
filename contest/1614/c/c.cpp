#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
using Node = std::array<int, 30>;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Node> a(n);
  std::vector<std::pair<int, int>> b(2 * m);
  for (int i = 0; i < m; ++i) {
    int l, r, x;
    std::cin >> l >> r >> x;
    b[i << 1] = {l - 1, x};
    b[i << 1 | 1] = {r, -x};
  }
  std::sort(b.begin(), b.end());
  Node now;
  now.fill(0);
  auto f = [&now](int x, int d) {
    int t = 0;
    while (x) {
      now[t++] += d * (x & 1);
      x >>= 1;
    }
  };
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < 2 * m && b[j].first == i) {
      if (b[j].second >= 0) {
        f(b[j].second, 1);
      } else {
        f(-b[j].second, -1);
      }
      ++j;
    }
    a[i] = now;
  }
  const int M = 1e9 + 7;
  auto add = [M](int& x, int y) {
    x += y;
    if (x >= M) x -= M;
  };
  Node one, zero;
  one.fill(0);
  zero.fill(1);
  for (int i = 0; i < n; ++i) {
    Node oneNew = one, zeroNew = zero;
    const auto& x = a[i];
    for (int j = 0; j < 30; ++j) {
      if (x[j]) {
        add(oneNew[j], zero[j]);
        add(zeroNew[j], one[j]);
      } else {
        add(oneNew[j], one[j]);
        add(zeroNew[j], zero[j]);
      }
    }
    std::swap(one, oneNew);
    std::swap(zero, zeroNew);
  }
  int ans = 0;
  for (int j = 0; j < 30; ++j) {
    ans = (ans + (1LL * one[j] << j)) % M;
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
