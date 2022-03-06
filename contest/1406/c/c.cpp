#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> q(n);
    int d[n] = {}, w[n] = {};
    for (int i = 1, x, y; i < n; ++i) {
      std::cin >> x >> y;
      --x; --y;
      q[x].emplace_back(y);
      q[y].emplace_back(x);
    }
    bool vis[n] = {};
    std::function<int(int)> dfs = [&](int u) -> int {
      vis[u] = true;
      ++d[u];
      for (auto v : q[u]) if (!vis[v]) {
        d[u] += dfs(v);
        w[u] = std::max(w[u], d[v]);
      }
      w[u] = std::max(w[u], n - d[u]);
      return d[u];
    };
    dfs(0);
    int mw = std::min_element(w, w + n) - w;
    std::memset(d, 0, sizeof(d));
    std::memset(w, 0, sizeof(w));
    std::memset(vis, 0, sizeof(vis));
    dfs(mw);
    int id = 0, md = 0;
    for (auto x : q[mw]) if (d[x] > md) {
      id = x;
      md = d[x];
    }
    std::memset(vis, 0, sizeof(vis));
    std::memset(w, 0, sizeof(w));
    std::memset(d, 0, sizeof(d));
    vis[mw] = 1;
    dfs(id);
    int id2 = 0;
    for (int i = 0; i < n; ++i) if (i != mw) {
      if (d[i] == 1) {
        id2 = i;
        break;
      }
    }
    std::cout << id2 + 1 << " " << q[id2][0] + 1 << std::endl;
    std::cout << id2 + 1 << " " << mw + 1 << std::endl;
  }
  return 0;
}
