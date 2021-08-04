#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  freopen("gcd.in","r",stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  LL ans = 0;
  while (cas--) {
    LL l, r;
    std::cin >> l >> r;
    if (l == r) ans = std::__gcd(l, ans);
    else ans = 1;
    std::cout << ans << std::endl;
  }
  return 0;
}