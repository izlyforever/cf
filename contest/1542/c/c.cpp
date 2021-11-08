#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

const LL M = 1e9 + 7;
// 根据情况换成 bool
void solve() {
  LL n;
  std::cin >> n;
  LL ans = 0, cur = 1;
  for (int i = 2; cur <= n; ++i) {
    LL now = std::lcm(cur, i);
    ans += (n / cur - n / now) * i;
    cur = now;
  }
  std::cout << ans % M << '\n';
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