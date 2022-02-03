#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  std::function<void(int, int, std::vector<int>&)> pdfs = [&](int u, int fa, std::vector<int>& dep) {
    for (auto v : e[u]) if (v != fa) {
      dep[v] = dep[u] + 1;
      pdfs(v, u, dep);
    }
  };
  std::vector<int> dep1(n + 1), p(n + 1);
  pdfs(1, 0, dep1);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin() + 1, p.end(), [&dep1](int i, int j) {
      return dep1[i] > dep1[j];
  });
  std::vector<int> ans(n + 1, INT_MAX);
  for (int u = 2; u <= n; ++u) {
    std::vector<int> dep(n + 1);
    pdfs(u, 0, dep);
    for (int i = 1, x = n, cur = 0; i <= n; ++i) {
      int j = p[i];
      cur = std::max(cur, dep[j] + x);
      while (x > 0 && cur >= dep1[j]) {
        ans[x] = std::min(ans[x], dep1[j]);
        --x;
        --cur;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    std::cout << ans[i] << " \n"[i == n];
  }
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
