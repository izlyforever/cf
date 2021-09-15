#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n);
  for (int i = 1, x; i < n; ++i) {
    std::cin >> x;
    e[x - 1].emplace_back(i);
  }
  std::vector<LL> a(n), d(n), ans(n);
  for (auto& x : a) std::cin >> x;
  std::function<LL(int)> dfs = [&](int u) -> LL {
    d[u] = e[u].empty();
    for (auto v : e[u]) {
      dfs(v);
      d[u] += d[v];
      a[u] += a[v];
      ans[u] = std::max(ans[u], ans[v]);
    }
    ans[u] = std::max(ans[u], (a[u] + d[u] - 1) / d[u]);
    return ans[u];
  };
  print(dfs(0));
  return 0;
}