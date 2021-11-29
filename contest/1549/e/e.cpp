#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int M = 1e9 + 7;
int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  const int N = 3 * (n + 1);
  std::vector<int> fac(N + 1), ifac(N + 1);
  fac[0] = 1;
  for (int i = 1; i <= N; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[N] = powMod(fac[N], M - 2);
  for (int i = N; i >= 1; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
  auto C = [&](int i) {
    return 1LL * fac[N] * ifac[N - i] % M * ifac[i] % M;
  };
  std::vector<int> ans(3 * n + 3);
  for (int i = 3 * n; i >= 1; --i) {
    int tmp = 1LL * (ans[i + 1] + ans[i + 2]) * 3 % M;
    tmp = C(i + 3) - tmp;
    if (tmp < 0) tmp += M;
    ans[i] = tmp;
  }
  while (q--) {
    int x;
    std::cin >> x;
    std::cout << ans[x] << '\n';
  }
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