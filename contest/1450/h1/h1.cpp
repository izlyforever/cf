#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353;

LL powMod(LL x, LL n) {
  LL r = 1;
  while (n) {
    if (n & 1) r = r * x % M;
    n >>= 1;   x = x * x % M;
  }
  return r;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::string s;
  std::cin >> n >> m >> s;

  std::vector<LL> fac(n + 1), ifac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % M;
  ifac[n] = powMod(fac[n], M - 2);
  for (int i = n; i >= 1; --i) ifac[i - 1] = ifac[i] * i % M;
  auto binom = [&](int n, int k) {
    return fac[n] * ifac[n - k] % M * ifac[k] % M;
  };

  int B[2] = {}, res[2] = {};
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') ++res[i % 2];
    else if (s[i] == 'b') ++B[i % 2];
  }
  int F = res[0] + res[1], x = B[1] + res[1] - B[0];

  LL r = 0;
  for (int i = (x + n) % 2; i <= F; i += 2) {
    (r += abs(x - i) * binom(F, i)) %= M;
  }
  r = r * powMod(2LL, F * (M - 2) % (M - 1)) % M;
  std::cout << r << std::endl;
  return 0;
}