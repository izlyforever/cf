#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
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
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}