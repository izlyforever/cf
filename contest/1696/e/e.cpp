#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int M = 1e9 + 7;
const int N = 4e5 + 2;

int powMod(int x, int n = M - 2) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

void solve() {
  std::vector<int> fac(N, 1), ifac(N, 1);
  for (int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[N - 1] = powMod(fac[N - 1]);
  for (int i = N - 1; i > 0; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
  auto C = [&](int n, int k) {
    return 1LL * fac[n] * ifac[k] % M * ifac[n - k] % M;
  };
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n + 1; ++i) {
    int x;
    std::cin >> x;
    if (x == 0) continue;
    ans += C(x - 1 + i, i);
    if (ans >= M) ans -= M;
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
