#include <bits/stdc++.h>
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i].first;
  for (int i = 0; i < n; ++i) std::cin >> a[i].second;
  std::sort(a.begin(), a.end());
  std::vector<int> b(n), p(n);
  for (int i = 0; i < n; ++i) b[i] = a[i].second - 1;
  int cnt = 0;
  for (int i = 0; i < n; ++i) if (p[i] == 0) {
    int now = i;
    while (p[now] == 0) {
      p[now] = 1;
      now = b[now];
    }
    ++cnt;
  }
  int ans = 1;
  const int M = 1e9 + 7;
  while (cnt--) if ((ans *= 2) >= M) ans -= M;
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