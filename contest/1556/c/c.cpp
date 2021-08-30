#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  LL ans = 0;
  for (int i = 0; i < n; i += 2) {
    LL now = 0, mx = 1;
    for (int j = i + 1; j < n; ++j) {
      if (j & 1) {
        now += a[j];
        if (now > a[i]) {
          ans += a[i] - mx + 1;
          break;
        }
        if (now >= mx) ans += std::min(a[j], now - mx + 1);
        mx = std::max(mx, now);
      } else {
        now -= a[j];
      }
    }
  }
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}