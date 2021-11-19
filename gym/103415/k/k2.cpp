#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
constexpr int M = 998244353;

int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}
void add(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}
void sub(int& x, int y) {
  x -= y;
  if (x < 0) x += M;
}

std::vector<int> DirichletProduct(const std::vector<int>& f, const std::vector<int>& g, int m) {
  std::vector<int> h(m + 1);
  for (int i = 1; i <= m; ++i) {
    for (int j = 1, ij = i; ij <= m; ij += i, ++j) {
      h[ij] = (h[ij] + 1LL * f[i] * g[j]) % M;
    }
  }
  return h;
};

int solve(int n, int m, int lcmMin, int gcdMax) {
  std::vector<int> mu(m + 1);
  mu[1] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = i + i; j <= m; j += i) {
      mu[j] -= mu[i];
    }
  }
  for (auto &x : mu) if (x < 0) x += M;
  std::vector<int> h(m + 1);
  for (int i = 1; i <= m; ++i) {
    for (int j = i; j <= m; j += i) {
      h[j] += i;
    }
  }
  for (auto &x : h) x = powMod(x, n);
  auto g = DirichletProduct(h, mu, m);
  std::vector<int> pn(m + 1);
  for (int i = 1; i <= m; ++i) pn[i] = powMod(i, n);
  std::vector<int> pnMu(m + 1);
  for (int i = 1; i <= m; ++i) pnMu[i] = 1LL * pn[i] * mu[i] % M;
  auto f = DirichletProduct(g, pnMu, m);
  auto sumf = f;
  for (int i = 1; i <= m; ++i) add(sumf[i], sumf[i - 1]);
  for (int i = 1; i <= m; ++i) add(pnMu[i], pnMu[i - 1]);
  
  std::vector<int> H(m + 1, -1), G(m + 1, -1), F(m + 1, -1);
  for (int i = 1; i <= m; ++i) {
    H[i] = powMod(1LL * i * (i + 1) / 2 % M, n);
  }
  auto getG = [&G, H, pnMu](int x) {
    if (G[x] != -1) return G[x];
    int ans = 0;
    for (int i = 1, j; i <= x; i = j + 1) {
      j = x / (x / i);
      ans = (ans + 1LL * H[x / i] * (pnMu[j] - pnMu[i - 1])) % M;
    }
    G[x] = ans < 0 ? ans + M : ans;
    return G[x];
  };
  for (int i = 1; i <= m; ++i) add(pn[i], pn[i - 1]);
  int ans = H[m];
  for (int i = gcdMax + 1, j; i <= m; i = j + 1) {
    j = m / (m / i);
    ans = (ans - 1LL * (pn[j] - pn[i - 1]) * getG(m / i)) % M;
  }
  if (--lcmMin) {
    gcdMax = std::min(gcdMax, lcmMin);
    for (int i = 1, j; i <= gcdMax; i = j + 1) {
      j = std::min(lcmMin / (lcmMin / i), gcdMax);
      ans = (ans - 1LL * (pn[j] - pn[i - 1]) * sumf[lcmMin / i]) % M;
    }
  }
  return ans < 0 ? ans + M : ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    int n, m, p, q;
    std::cin >> n >> m >> p >> q;
    std::cout << solve(n, m, p, q) << '\n';
  }
  return 0;
}
