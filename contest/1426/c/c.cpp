#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    // may get a TLE
    // int r = n - 1;
    // for (int i = 1; i <= n; i = n / (n / i) + 1) {
    //   r = std::min(r, i - 2 + (n + i - 1) / i);
    // }
    // 可能取到的最小值
    int r = 2 * (std::sqrt(n) - 1);
    while ((r / 2 + 1) * (r - r / 2 + 1) < n) ++r;
    print(r);
  }
  return 0;
}