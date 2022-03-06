#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    if (a[i] == 0) a[i] = -1;
  }
  std::vector<std::vector<int>> e(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  std::vector<int> ans(n + 1);
  std::function<void(int, int)> pdfs = [&](int u, int fa) -> void {
    ans[u] = a[u];
    for (auto v : e[u]) if (v != fa) {
      pdfs(v, u);
      if (ans[v] > 0) ans[u] += ans[v];
    }
  };
  pdfs(1, 0);
  // 预处理出 1 为根的结果，然后进行换根 DP
  std::function<void(int, int)> dfs = [&](int u, int fa) -> void {
    for (auto v : e[u]) if (v != fa) {
      if (ans[v] < 0) {
        if (ans[u] > 0) ans[v] = a[v] + ans[u];
      } else {
        ans[v] = std::max(ans[v], ans[u]);
      }
      dfs(v, u);
    }
  };
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
  return 0;
}
