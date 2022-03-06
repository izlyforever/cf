#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> vis(n + 1);
  vis[1] = 1;
  for (int i = 2; i <= n; ++i) {
    LL j = i * i;
    if (j > n) break;
    while (j <= n) {
      vis[j] = 1;
      j *= i;
    }
  }
  int lgn = std::__lg(n);
  std::vector<int> a(lgn + 1);
  {
    std::vector<int> cnt(lgn * m + 1, 1);
    int c = 0;
    for (int i = 1; i <= lgn; ++i) {
      for (int j = 1, t = i; j <= m; ++j, t += i) {
        c += cnt[t];
        cnt[t] = 0;
      }
      a[i] = c;
    }
  }
  LL ans = 1;
  for (int i = 2; i <= n; ++i) if (!vis[i]) {
    int cnt = 0;
    LL j = i;
    while (j <= n) {
      ++cnt;
      j *= i;
    }
    ans += a[cnt];
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
