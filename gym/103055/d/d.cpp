#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const LL inf = INT64_MAX / 2;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> len(n + 1);
  for (int i = 2; i <= n; ++i) len[i] = len[i >> 1] + 1;
  std::vector<std::vector<std::pair<int, LL>>> e(n + 1);
  for (int i = 0, u, v; i < m; ++i) {
    LL w;
    std::cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  auto check = [](int u, int v) {
    if (u < v) return false;
    int d = std::__lg(u) - std::__lg(v);
    return (u >> d) == v;
  };
  std::vector<std::vector<LL>> dist(n + 1, std::vector<LL>(len[n] + 1, inf));
  for (int i = 1; i <= n; ++i) {
    std::priority_queue<std::pair<LL, int>> Q;
    int dep = len[i];
    dist[i][dep] = 0;
    Q.push({0, i});
    while (!Q.empty()) {
      auto [du, u] = Q.top();
      Q.pop();
      if (-du != dist[u][dep]) continue;
      for (auto [v, w] : e[u]) if (check(v, i)) {
        if (dist[v][dep] > dist[u][dep] + w) {
          dist[v][dep] = dist[u][dep] + w;
          Q.push({-dist[v][dep], v});
        }
      }
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int u, v;
    std::cin >> u >> v;
    LL ans = inf;
    int now = u;
    while (now) {
      if (check(v, now)) ans = std::min(ans, dist[u][len[now]] + dist[v][len[now]]);
      now >>= 1;
    }
    std::cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}