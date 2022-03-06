#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> e(n), g(n);
  std::vector<std::tuple<int, int, int>> edge(n - 1);
  for (auto &[x, y, v] : edge) {
    std::cin >> x >> y >> v;
    --x; --y;
    if (v != -1) {
      if (__builtin_parity(v)) {
        e[x].emplace_back(y);
        e[y].emplace_back(x);
      } else {
        g[x].emplace_back(y);
        g[y].emplace_back(x);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    int x, y, p;
    std::cin >> x >> y >> p;
    --x; --y;
    if (p) {
      e[x].emplace_back(y);
      e[y].emplace_back(x);
    } else {
      g[x].emplace_back(y);
      g[y].emplace_back(x);
    }
  }
  std::vector<int> val(n, -1), vis(n);
  auto bfs = [&](int root) -> bool {
    if (vis[root]) return true;
    std::queue<int> Q;
    Q.push(root);
    val[root] = 0;
    vis[root] = 1;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto v : e[u]) {
        if (val[v] == -1) {
          val[v] = 1 - val[u];
        } else if (val[v] != 1 - val[u]) {
          return false;
        }
        if (!vis[v]) {
          vis[v] = 1;
          Q.push(v);
        }
      }
      for (auto v : g[u]) {
        if (val[v] == -1) {
          val[v] = val[u];
        } else if (val[v] != val[u]) {
          return false;
        }
        if (!vis[v]) {
          vis[v] = 1;
          Q.push(v);
        }
      }
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (!bfs(i)) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
  for (auto &[x, y, v] : edge) {
    if (v == -1) v = val[x] ^ val[y];
    std::cout << ++x << ' ' << ++y << ' ' << v << '\n';
  }
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
