#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
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

int solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  if (k == 0) return 1;

  std::vector<int> fac(n + 1), ifac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[n] = powMod(fac[n], M - 2);
  for (int i = n; i >= 1; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
  auto C = [&](int x, int y) -> int {
    if (y < 0 || y > x) return 0;
    return 1LL * fac[x] * ifac[y] % M * ifac[x - y] % M;
  };

  int l = 0, r = 0, cnt = 0;
  while (r < n && cnt < k) {
    while (r < n && s[r] == '0') ++r;
    if (r < n) {
      if (++cnt == k) break;
    }
    ++r;
  }
  if (r >= n) return 1;

  int ans = 0;
  while (r < n) {
    ++r;
    while (r < n && s[r] == '0') ++r;
    ans += C(r - l, k);
    if (ans >= M) ans -= M;
    while (l < n && s[l] == '0') ++l;
    ++l;
    if (r < n) {
      ans -= C(r - l, k - 1);
      if (ans < 0) ans += M;
    }
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
