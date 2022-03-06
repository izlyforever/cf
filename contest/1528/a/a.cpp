#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];
    std::vector<std::vector<int>> e(n);
    for (int i = 1, u, v; i < n; ++i) {
      std::cin >> u >> v;
      --u; --v;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    std::vector<LL> f(n), g(n);
    std::function<void(int, int)> dfs = [&](int u, int fa) {
      for (auto v : e[u]) if (v != fa) {
        dfs(v, u);
        LL tf = std::max(f[v] + abs(a[u] - a[v]), g[v] + abs(a[u] - b[v]));
        LL tg = std::max(f[v] + abs(b[u] - a[v]), g[v] + abs(b[u] - b[v]));
        f[u] += tf;
        g[u] += tg;
      }
    };
    dfs(0, 0);
    std::cout << std::max(f[0], g[0]) << '\n';
  }
  return 0;
}
