#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  std::vector<int> a(n);
  int ans = 1;
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    for (auto v : e[u]) if (v != fa) {
      dfs(v, u);
      if (a[v] == 0) ++a[u];
    }
    if (a[u] > 0) ans += a[u] - 1;
  };
  dfs(0, 0);
  // for (int i = 0; i < n; ++i) std::cerr << a[i] << ' ';
  // std::cerr << '\n';
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}