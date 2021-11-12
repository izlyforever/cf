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
    for (int i = 1; i < n; ++i) {
      int u, v;
      std::cin >> u >> v;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    // 采用 jiangly 的做法，通过时间戳来搞定
    std::vector<int> sz(n), in(n), out(n);
    int cnt = 0;
    std::function<void(int, int)> dfs = [&](int u, int fa) {
      in[u] = cnt++;
      for (auto v : e[u]) if (v != fa) dfs(v, u);
      out[u] = cnt;
      sz[u] = out[u] - in[u];
    };
    dfs(0, -1);
    std::vector<LL> ans(n + 1);
    int l = -1;
    for (auto v : e[0]) {
      ans[0] += 1LL * sz[v] * (sz[v] - 1) / 2;
      if (in[v] <= in[1] && in[1] < out[v]) l = v;
    }
    ans[1] = 1LL * n * (n - 1) / 2 - ans[0];
    int u = 1, v = -1;
    for (int i = 1; i < n; ++i) {
      bool ok = false;
      if (in[i] <= in[u] && in[u] < out[i]) ok = true;
      if (v != -1 && in[i] <= in[v] && in[v] < out[i]) ok = true;
      if (!ok) {
        if (in[u] <= in[i] && in[i] < out[u]) {
          u = i;
                } else if ((v == -1 && !(in[l] <= in[i] && in[i] < out[l])) || (in[v] <= in[i] && in[i] < out[v])) {
          v = i;
        } else break;
      }
      if (v == -1) {
        ans[i + 1] = 1LL * sz[u] * (n - sz[l]);
      } else {
        ans[i + 1] = 1LL * sz[u] * sz[v];
      }
    }
    // for (int i = 0; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
    for (int i = 1; i < n; ++i) ans[i] -= ans[i + 1];
    for (int i = 0; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
  }
  return 0;
}