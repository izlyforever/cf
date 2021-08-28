#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

const int M = 998244353;
int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

// 根据情况换成 bool
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
  std::vector<int> a(n + 1), f(n + 1), ans(n + 1), p(n + 1);
  std::function<bool(int, int)> dfs = [&](int u, int i) -> bool {
    for (auto v : e[u]) if (v != p[u]) {
      p[v] = u;
      if (!dfs(v, i)) return false;
    }
    if (a[u] % i == 0) {
      ++a[p[u]];
      return true;
    }
    return a[u] % i == i - 1;
  };
  f[1] = powMod(2, n - 1);
  for (int i = n - 1; i > 1; --i) if ((n - 1) % i == 0) {
    std::fill(a.begin(), a.end(), 0);
    if (dfs(1, i)) f[i] = 1;
  }
  for (int i = n - 1; i >= 1; --i) {
    ans[i] = f[i];
    for (int j = i * 2; j < n; j += i) ans[i] -= ans[j];
  }
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
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