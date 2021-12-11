#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int powMod(int x, int n, int M) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

int solve() {
  const int M = 998244353;
  int n;
  std::cin >> n;
  std::vector<int> l(n), r(n);
  std::map<char, int> mp{{'?', 0}, {'B', 1}, {'W', 2}};
  int countl[3]{}, countr[3]{};
  for (int i = 0; i < n; ++i) {
    char cl, cr;
    std::cin >> cl >> cr;
    l[i] = mp[cl];
    r[i] = mp[cr];
    ++countl[l[i]];
    ++countr[r[i]];
  }
  for (int _ = 0; _ < 3; ++_) {
    for (int c = 1; c < 3; ++c) if (countl[c] == n) {
      return countr[c] == 0;
    }
    for (int c = 1; c < 3; ++c) if (countr[c] == n) {
      return countl[c] == 0;
    }
    for (int c = 1; c < 3; ++c) if (countl[c] == n - 1) {
      for (int i = 0; i < n; ++i) if (l[i] != c) {
        if (r[i] && r[i] != 3 - c) return 0;
        r[i] = 3 - c;
      }
    }
    for (int c = 1; c < 3; ++c) if (countr[c] == n - 1) {
      for (int i = 0; i < n; ++i) if (r[i] != c) {
        if (l[i] && l[i] != 3 - c) return 0;
        l[i] = 3 - c;
      }
    }
  }
  std::vector<int> fac(n + 1, 1), ifac(n + 1, 1);
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[n] = powMod(fac[n], M - 2, M);
  for (int i = n; i >= 1; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
  auto C = [&](int x, int y) -> int {
    if (y < 0 || y > x) return 0;
    return 1LL * fac[x] * ifac[y] % M * ifac[x - y] % M;
  };
  int cl = 0, cr = 0, ct = 0;
  for (int i = 0; i < n; ++i) {
    if (l[i] == 0) ++cl;
    else if (l[i] == 2) ++ct;
    if (r[i] == 0) ++cr;
    else if (r[i] == 1) --ct;
  }
  int ans = 0;
  for (int i = 0; i <= cl; ++i) {
    ans = (ans + 1LL * C(cl, i) * C(cr, i + ct)) % M;
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}