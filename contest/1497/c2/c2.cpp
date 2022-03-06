#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    // 思考了太久，哎。
    for (int i = 3; i < k; ++i) {
      std::cout << "1 ";
      --n;
    }
    int x = n & -n;
    if (x == n) {
      std::cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << '\n';
    } else {
      std::cout << x << ' ' << (n - x) / 2 << ' ' << (n - x) / 2 << '\n';
    }
  }
  return 0;
}
