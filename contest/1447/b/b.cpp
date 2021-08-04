#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    n *= m;
    int r = 0, cnt = 0, mx = INT_MAX;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      r += abs(x);
      mx = std::min(mx, abs(x));
      if (x <= 0) ++cnt;
    }
    if (cnt & 1) r -= 2 * mx;
    std::cout << r << std::endl;
  }
  return 0;
}