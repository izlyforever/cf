#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
constexpr int M = 1e9 + 7;

int powMod(int x, int n = M - 2) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

void norm(int& x) {
  if (x >= M) x -= M;
}

void solve() {
  int n;
  LL l, r, z;
  std::cin >> n >> l >> r >> z;

  std::vector<int> c(n + 1);
  c[0] = 1;
  for (int i = 1; i <= n; ++i) {
    c[i] = 1LL * c[i - 1] * (n - i + 1) % M * powMod(i) % M;
  }
  auto f = [&](LL x) -> int {
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 59; i >= 0; --i) {
      int xi = x >> i & 1;
      int zi = z >> i & 1;
      std::vector<int> pd(n + 1);
      for (int j = 0; j <= n; ++j) {
        int yj = 2 * j + xi;
        for (int k = zi; k <= n && k <= yj; k += 2) {
          int t = std::min(n, yj - k);
          pd[t] = (pd[t] + 1LL * dp[j] * c[k]) % M;
        }
      }
      std::swap(dp, pd);
    }
    return std::accumulate(dp.begin(), dp.end(), 0LL) % M;
  };
  int ans = f(r) - f(l - 1) + M;
  norm(ans);
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
