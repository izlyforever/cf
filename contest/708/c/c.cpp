#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  // subtree[u] 表示以 u 为根的子树中 sz 不超过 n / 2 中最大的子子树的大小。
  // mx[u], mmx[u] 分别表示以表示以 u 为根的子树中 sz 不超过 n / 2 的中最大和次大的真子子树的大小。
  std::vector<int> sz(n + 1), mx(n + 1), mmx(n + 1), subtree(n + 1);
  std::function<void(int, int)> pdfs = [&](int u, int fa) -> void {
    sz[u] = 1;
    for (auto v : e[u]) if (v != fa) {
      pdfs(v, u);
      sz[u] += sz[v];
      subtree[u] = std::max(subtree[u], subtree[v]);
      if (subtree[v] > mx[u]) {
        mmx[u] = mx[u];
        mx[u] = subtree[v];
      } else if (subtree[v] > mmx[u]) {
        mmx[u] = subtree[v];
      }
    }
    if (sz[u] <= n / 2) subtree[u] = sz[u];
  };
  pdfs(1, 0);
  std::vector<int> mxsub(n + 1), ans(n + 1);
  std::function<void(int, int)> dfs = [&](int u, int fa) -> void {
    ans[u] = 1;
    mxsub[u] = mxsub[fa];
    if (subtree[u] == mx[fa]) {
      mxsub[u] = std::max(mxsub[fa], mmx[fa]);
    } else {
      mxsub[u] = std::max(mxsub[fa], mx[fa]);
    }
    if (sz[1] - sz[u] <= n / 2) mxsub[u] = std::max(mxsub[u], sz[1] - sz[u]);
    if (sz[u] <= n / 2) {
      if (sz[1] - sz[u] - mxsub[u] > n / 2) ans[u] = 0;
    } else {
      for (auto v : e[u]) if (v != fa && sz[v] > n / 2) {
        if (sz[v] - subtree[v] > n / 2) ans[u] = 0;
      }
    }
    for (auto v : e[u]) if (v != fa) dfs(v, u);
  };
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
  return 0;
}
