#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int powMod(int x, int n, int p) {
  int r = 1;
  while (n) {
    if (n&1) r = 1LL * r * x % p;
    n >>= 1; x = 1LL * x * x % p;
  }
  return r;
}
// 一般情况下 N < 1e6, M 必须是一个小于 INT_MAX 的素数
namespace Binom {
int N = 0, M = 1e9 + 7;
std::vector<int> fac, ifac;
void setMod(int m) {
  M = m;
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[N - 1] = powMod(fac[N - 1], M - 2, M);
  for (int i = N - 1; i; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
}
// 请确保 n < m，否则无法保证后面的正确性
void init(int n, int m = M) {
  N = n;
  fac.resize(N);
  ifac.resize(N);
  setMod(m);
}
// 需要预处理小于 n 的所有值！
int binom(int n, int k) {
  if (n < 0 || n < k) return 0;
  return 1LL * fac[n] * ifac[k] % M * ifac[n - k] % M;
}
// 一般说来需要预处理出小于 M 的所有值，且 M 是素数！
int lucas(int n, int k) {
  int r = 1;
  while (n && k) {
    int np = n % M, kp = k % M;
    if (np < kp) return 0;
    r = 1LL * r * binom(np, kp) % M;
    n /= M; k /= M;
  }
  return r;
}
} // namespace Binom
// 模板例题：https://www.luogu.com.cn/problem/P3807

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n + 1);
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  std::vector<int> dep(n + 1, INT_MAX);
  std::function<void(int, int)> pdfs = [&](int u, int fa) {
    for (auto v : e[u]) if (v != fa) {
      pdfs(v, u);
      dep[u] = std::min(dep[u], dep[v] + 1);
    }
    if (dep[u] == INT_MAX) dep[u] = 1;
  };
  pdfs(1, 0);
  const int M = 998244353;
  Binom::init(n + 2, M);
  auto check = [&](int x) {
    if (x == 1) return e[x].size() == 1;
    return e[x].size() == 2;
  };
  std::function<int(int, int, int)> dfs = [&](int d, int u, int fa) -> int {
    if (dep[u] == 1) return 1;
    int ans = 1;
    if (d < dep[u] && check(u)) {
      int v = u, f = fa;
      while (check(v)) {
        int tmp = v;
        v = (*e[v].begin() != f ? *e[v].begin() : *e[v].rbegin());
        f = tmp;
      }
      if (d >= dep[v]) {
        ans = 1LL * ans * Binom::binom(dep[u] - dep[v] + 1, d - dep[v] + 1) * dfs(dep[v], v, f) % M;
      } else {
        ans = dfs(d, v, f);
      }
    } else {
      if (d == dep[u]) --d;
      for (auto v : e[u]) if (v != fa) {
        ans = 1LL * ans * dfs(d, v, u) % M;
      }
    }
    return ans;
  };
  std::cout << dfs(dep[1], 1, 0) << '\n';
  return 0;
}