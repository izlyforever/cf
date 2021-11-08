#include <bits/stdc++.h>
using LL = long long;

int powMod(int x, int n, int p) {
  int r = 1;
  while (n) {
    if (n&1) r = 1LL * r * x % p;
    n >>= 1; x = 1LL * x * x % p;
  }
  return r;
}

const int M = 998244353;
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> s(n + 1), rk(n + 1);
  s[0] = n;
  for (int i = 1; i <= n; ++i) std::cin >> s[i];
  for (int i = 0; i <= n; ++i) rk[s[i]] = i;
  int equal = n - 1;
  for (int i = 1; i < n; ++i) {
    if (rk[s[i] + 1] > rk[s[i + 1] + 1]) --equal;
  }
  int ans = 1, fac = 1;
  for (int i = 0; i < n; ++i) {
    ans = 1LL * ans * (k + equal - i) % M;
    fac = 1LL * fac * (i + 1) % M;
  }
  ans = 1LL * ans * powMod(fac, M - 2, M) % M;
  std::cout << ans << '\n';
  return 0;
}