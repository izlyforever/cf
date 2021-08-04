#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n);
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    if (--u == --v) continue;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  int a, b;
  std::cin >> a >> b;
  --a; --b;
  std::vector<int> dep(n);
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : e[u]) if (v != fa) {
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  };
  dfs(a, -1);
  std::cout << (dep[b] & 1 ?  "Yes\n" : "No\n");
  return 0;
}