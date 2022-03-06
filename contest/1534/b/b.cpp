#include <bits/stdc++.h>
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      int mx = std::max(a[i - 1], a[i + 1]);
      ans += a[i] - mx;
      a[i] = mx;
    }
  }
  for (int i = 1; i <= n + 1; ++i) ans += abs(a[i] - a[i - 1]);
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
