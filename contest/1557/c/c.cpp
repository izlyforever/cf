#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
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
  int n, k;
  std::cin >> n >> k;
  int ans = 1, x = powMod(2, n - 1);
  int c = (x + 1) % M;
  if (n & 1) {
    ans = powMod(c, k);
  } else {
    int n2 = x * 2 % M;
    if (c == 0) {
      ans = (1LL * k * powMod(n2, k - 1) + powMod(n2, k)) % M;
    } else {
      ans = (1LL * (powMod(n2, k) - powMod(x - 1, k) + M) * powMod(x + 1, M - 2) + powMod(x - 1, k))% M;
    }
  }
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}