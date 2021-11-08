#include <bits/stdc++.h>
using LL = long long;

// 根据情况换成 bool
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
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}