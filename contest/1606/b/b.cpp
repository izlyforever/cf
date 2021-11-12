#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  LL n, k;
  std::cin >> n >> k;
  LL now = 1, ans = 0;
  while (now < k) {
    now *= 2;
    ++ans;
  }
  ans += (n - now + k - 1) / k;
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}