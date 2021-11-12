#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> ans(n);
  auto f = [&](std::vector<std::vector<int>> e) {
    std::vector<int> in(n);
    for (auto& u : e) for (auto v : u) ++in[v];
    std::queue<int> Q;
    int alive = n;
    for (int i = 0; i < n; ++i) if (in[i] == 0) Q.push(i), --alive;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (Q.empty()) ans[u] += alive;
      for (auto v : e[u]) {
        --in[v];
        if (in[v] == 0) {
          Q.push(v);
          --alive;
        }
      }
    }
  };
  std::vector<std::vector<int>> e(n), g(n);
  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    --u; --v;
    e[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  f(e);
  f(g);
  int cnt = 0;
  for (int i = 0; i < n; ++i) if (ans[i] == n - 1) ++cnt;
  std::cout << cnt << '\n';
  return 0;
}