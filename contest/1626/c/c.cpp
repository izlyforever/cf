#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<LL> k(n + 1), h(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> k[i];
  for (int i = 1; i <= n; ++i) std::cin >> h[i];
  auto a = h;
  for (int i = n; i > 0; --i) {
    a[i - 1] = std::max(a[i - 1], a[i] + k[i - 1] - k[i]);
  }
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > k[i] - k[i - 1]) {
      a[i] = a[i - 1] + k[i] - k[i - 1];
    } else {
      ans += a[i - 1] * (a[i - 1] + 1);
    }
  }
  ans += a[n] * (a[n] + 1);
  std::cout << ans / 2 << '\n';
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