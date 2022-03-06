#include <bits/stdc++.h>
using LL = long long;

constexpr int M = 1e9 + 7;
constexpr int inv2 = (M + 1) / 2;
int inv(int a) {
  return a == 1 ? 1 : 1LL * (M - M / a) * inv(M % a) % M;
}

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
  int timer = 0;
  std::vector<int> dep(n + 1), in(n + 1), out(n + 1), fa(n + 1);
  std::function<void(int)> dfs = [&](int u) {
    in[u] = timer++;
    for (auto v : e[u]) if (v != fa[u]) {
      dep[v] = dep[u] + 1;
      fa[v] = u;
      dfs(v);
    }
    out[u] = timer;
  };
  std::vector<int> a(n + 1, 1), fac(n + 1, 1), ifac(n + 1, 1);
  for (int i = 1; i <= n; ++i) a[i] = 1LL * a[i - 1] * inv2 % M;
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[n] = inv(fac[n]);
  for (int i = n; i >= 1; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
  auto g = [&](int i, int j) {
    if (i == 0) return 1;
    int ans = 0;
    for (int k = 0; k < j; ++k) {
      ans = (ans + 1LL * fac[i - 1 + k] * ifac[k] % M * ifac[i - 1] % M * a[i + k]) % M;
    }
    return ans;
  };
  auto f = [&](int rt) -> int {
    timer = 0;
    dep[rt] = fa[rt] = 0;
    dfs(rt);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        int tmp = i;
        while (in[tmp] > in[j] || out[tmp] < out[j]) tmp = fa[tmp];
        ans += g(dep[i] - dep[tmp], dep[j] - dep[tmp]);
        if (ans >= M) ans -= M;
      }
    }
    return ans % M;
  };
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if ((ans += f(i)) >= M) ans -= M;
  }
  ans = 1LL * ans * inv(n) % M;
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
