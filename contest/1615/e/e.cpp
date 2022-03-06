#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int k, n;
  std::cin >> n >> k;
  std::vector<std::vector<int>> e(n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    e[x].emplace_back(y);
    e[y].emplace_back(x);
  }
  std::vector<int> dep(n), fa(n);
  std::function<void(int)> dfs = [&](int u) {
    for (auto v : e[u]) if (v != fa[u]) {
      dep[v] = dep[u] + 1;
      fa[v] = u;
      dfs(v);
    }
  };
  dfs(0);
  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&dep](int i, int j) {
    return dep[i] > dep[j];
  });
  std::vector<int> vis(n), val(n);
  for (auto x : p) {
    val[x] = 0;
    int cur = x;
    while (vis[cur] == 0) {
      ++val[x];
      vis[cur] = 1;
      cur = fa[cur];
    }
  }
  std::sort(val.begin(), val.end(), std::greater<>());
  int left = n;
  LL ans = INT64_MIN;
  for (int i = 0; i <= k; ++i) {
    int b = std::min(n / 2, left);
    ans = std::max(ans, 1LL * b * (b - n) + 1LL * i * (n - i));
    if (i < k) left -= val[i];
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
