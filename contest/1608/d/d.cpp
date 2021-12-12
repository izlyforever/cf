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
  int n;
  std::cin >> n;
  int n2 = n * 2;
  std::vector<int> fac(n2 + 1, 1), ifac(n2 + 1, 1);
  for (int i = 1; i <= n2; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[n2] = powMod(fac[n2], M - 2);
  for (int i = n2; i >= 1; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
  auto C = [&](int x, int y) -> int {
    if (y < 0 || y > x) return 0;
    return 1LL * fac[x] * ifac[y] % M * ifac[x - y] % M;
  };
  std::map<char, int> mp{{'?', 0}, {'B', 1}, {'W', 2}};
  int wc[3]{}, wwc[3]{}, ww = 0;
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    char cl, cr;
    std::cin >> cl >> cr;
    int l = mp[cl];
    int r = mp[cr];
    ++wc[l];
    ++wc[r];
    ++wwc[l];
    if (r == 0) {
      ++wwc[r];
      if (l == 0) ++ww;
    } else {
      if (l == r) flag = true;
      ++wwc[3 - r];
    }
  }
  if (wc[1] > n || wc[2] > n) return 0;
  int ans = C(n2 - wc[1] - wc[2], n - wc[1]);
  if (!flag) {
    ans -= powMod(2, ww);
    if (ans < 0) ans += M;
    if (wwc[1] == 0) ++ans;
    if (wwc[2] == 0) ++ans;
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