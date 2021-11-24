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
void sub(int& x, int y) {
  x -= y;
  if (x < 0) x += M;
}
void add(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}
void solve() {
  int n;
  std::cin >> n;
  int cnt[31]{};
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++cnt[__builtin_ctz(x)];
  }
  int ans = powMod(2, n) - 1;
  int now = n - cnt[0];
  for (int i = 1; i < 31; ++i) if (cnt[i]) {
    sub(ans, powMod(2, now - 1));
    now -= cnt[i];
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