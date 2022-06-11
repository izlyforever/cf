#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<std::vector<int>> e(n);
  std::vector<int> fa(n), sz(n), ans(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  std::function<void(int)> dfs = [&](int u) -> void {
    sz[u] = 1;
    int v1 = -1, v2 = -1;
    for (auto &v : e[u]) if (v != fa[u]) {
      fa[v] = u;
      dfs(v);
      sz[u] += sz[v];
      if (v1 == -1) {
        v1 = v;
      } else if (v2 == -1) {
        v2 = v;
      }
    }
    if (v1 != -1) {
      if (v2 != -1) {
        ans[u] = std::max(ans[v1] + sz[v2], ans[v2] + sz[v1]) - 1;
      } else {
        ans[u] = sz[v1] - 1;
      }
    }
  };
  dfs(0);
  std::cout << ans[0] << '\n';
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
