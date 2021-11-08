#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
const int M = 1e9 + 7;
void solve() {
  int n, k;
  std::cin >> n >> k;
  int ans = 0, now = 1;
  while (k) {
    if (k & 1) ans = (ans + now) % M;
    now = 1LL * now * n % M;
    k >>= 1;
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