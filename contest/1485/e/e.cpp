#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> e(n);
    for (int i = 1, x; i < n; ++i) {
      std::cin >> x;
      --x;
      e[i].emplace_back(x);
      e[x].emplace_back(i);
    }
    std::vector<int> a(n), d(n), fa(n);
    for (int i = 1; i < n; ++i) std::cin >> a[i];
    std::function<void(int)> dfs = [&](int u) {
      for (auto v : e[u]) if (v != fa[u]) {
        fa[v] = u;
        d[v] = d[u] + 1;
        dfs(v);
      }
    };
    dfs(0);
    int md = *std::max_element(d.begin(), d.end());
    std::vector<std::vector<int>> f(1 + md);
    for (int i = 0; i < n; ++i) f[d[i]].emplace_back(i);
    std::vector<LL> dp(n);
    for (int i = 1; i <= md; ++i) {
      int mx = INT_MIN, mn = INT_MAX;
      LL padd = INT64_MIN, pmin = INT64_MIN;
      for (auto x : f[i]) {
        mx = std::max(mx, a[x]);
        mn = std::min(mn, a[x]);
        padd = std::max(padd, dp[fa[x]] + a[x]);
        pmin = std::max(pmin, dp[fa[x]] - a[x]);
      }
      for (auto x : f[i]) {
        dp[x] = std::max({dp[fa[x]] + std::max(abs(mx - a[x]), abs(mn - a[x])), padd - a[x], pmin + a[x]});
      }
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << "\n";
  }
  return 0;
}