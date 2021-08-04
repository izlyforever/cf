#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), c(n + 1);
  std::vector<std::vector<int>> p(n + 1);
  // p[0].emplace_back(0);
  std::cin >> a[0] >> c[0];
  for (int i = 1; i <= n; ++i) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x;
      std::cin >> x >> a[i] >> c[i];
      p[i].emplace_back(x);
      int j = 0;
      while (x && a[x]) {
        if (j < (int)p[x].size()) x = p[x][j];
        else x = 0;
        if (a[x]) p[i].emplace_back(x);
        ++j;
      }
    } else {
      int x, w;
      std::cin >> x >> w;
      int sm = 0;
      LL ans = 0;
      while (w && a[x]) {
        int t = x;
        while (!p[t].empty()) {
          while (!p[t].empty() && a[p[t].back()] == 0) p[t].pop_back();
          if (!p[t].empty()) t = p[t].back();
        }
        int wt = std::min(w, a[t]);
        w -= wt;
        a[t] -= wt;
        sm += wt;
        ans += 1LL * wt * c[t];
      }
      std::cout << sm << ' ' << ans << std::endl;
    }
  }
  return 0;
}