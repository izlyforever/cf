#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<LL> b(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> b[i];
  LL ans = 0;
  LL u = 0, a = 0;
  std::vector<LL> c(n + 1), d(n + 1);
  for (int i = n; i > 0; --i) {
    u += c[i];
    a += d[i];
    LL df = b[i] - u * i - a;
    if (df > 0) {
      int v = std::min(i, k);
      LL t = (df + v - 1) / v;
      u += t;
      a += t * (v - i);
      ans += t;
      if (i >= v) {
        c[i - v] -= t;
        d[i - v] -= t * (v - i);
      }
    }
  }
  std::cout << ans << '\n';
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
