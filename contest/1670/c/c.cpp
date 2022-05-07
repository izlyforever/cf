#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int M = 1e9 + 7;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), d(n), p(n);
  for (auto &x : a) {
    std::cin >> x;
    --x;
  }
  for (auto &x : b) {
    std::cin >> x;
    --x;
  }
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    if (x) d[--x] = 1;
  }
  for (int i = 0; i < n; ++i) {
    p[a[i]] = b[i];
  }
  std::vector<int> vis(n);
  int cnt = 0;
  for (int i = 0; i < n; ++i) if (!vis[i]) {
    if (p[i] == i) continue;
    int u = i;
    bool flag = true;
    do {
      vis[u] = 1;
      u = p[u];
      if (d[u]) flag = false;
    } while (u != i);
    if (flag) ++cnt;
  }
  int ans = 1;
  for (int i = 0; i < cnt; ++i) {
    ans *= 2;
    if (ans >= M) ans -= M;
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
