#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::set<int>> e(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    e[u].insert(v);
    e[v].insert(u);
  }
  std::vector<int> fib{1, 1};
  while (fib.back() < n) fib.emplace_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
  if (fib.back() != n) {
    std::cout << "NO\n";
    return 0;
  }
  std::vector<int> sz(n), fa(n);
  bool flag = true;
  std::function<void(int, int)> solve = [&](int u, int i) {
    if (i <= 3 || !flag) return;
    int r = -1;
    std::function<void(int)> dfs = [&](int u) {
      sz[u] = 1;
      for (auto v : e[u]) if (v != fa[u]) {
        fa[v] = u;
        dfs(v);
        sz[u] += sz[v];
      }
      if (sz[u] == fib[i - 1] || sz[u] == fib[i - 2]) {
        r = u;
      }
    };
    fa[u] = -1;
    dfs(u);
    if (r == -1) {
      flag = false;
      return;
    }
    e[r].erase(fa[r]);
    e[fa[r]].erase(r);
    if (sz[r] == fib[i - 1]) {
      solve(fa[r], i - 2);
      solve(r, i - 1);
    } else {
      solve(fa[r], i - 1);
      solve(r, i - 2);
    }
  };
  solve(0, fib.size() - 1);
  std::cout << (flag ? "YES\n" : "NO\n");
  return 0;
}
