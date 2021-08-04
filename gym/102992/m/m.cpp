#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> p(n), hp(n);
    std::vector<std::vector<int>> e(n);
    for (int i = 1; i < n; ++i) {
      std::cin >> p[i];
      --p[i];
      e[i].emplace_back(p[i]);
      e[p[i]].emplace_back(i);
    }
    for (auto &x : hp) std::cin >> x;
    // f[i][j] 表示以 i 为根（不包含节点 i）选取 j 个节点的最小代价（相当于已经删除了 sz[i] - j 个节点)。
    // g[i][j] 表示以 i 为根（包含节点 i）选取 j 个节点的最小代价。
    std::vector<std::vector<LL>> f(n, std::vector<LL>(n + 1, INT64_MAX >> 2));
    auto g = f;
    std::vector<int> sz(n);
    std::function<void(int)> dfs = [&](int u) {
      f[u][0] = 0;
      g[u][1] = hp[u];
      sz[u] = 1;
      for (auto v : e[u]) if (v != p[u]) {
        dfs(v);
        for (int i = sz[u]; i >= 0; --i) {
          for (int j = sz[v]; j >= 0; --j) {
            f[u][i + j] = std::min(f[u][i + j], f[u][i] + std::min(f[v][j], g[v][j]));
            g[u][i + j] = std::min(g[u][i + j], g[u][i] + std::min(f[v][j], g[v][j] + hp[v]));
          }
        }
        sz[u] += sz[v];
      }
    };
    dfs(0);
    for (int i = n; i >= 0; --i) {
      std::cout << std::min(f[0][i], g[0][i]) << " \n"[i == 0];
    }
  }
  return 0;
}