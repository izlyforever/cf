#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int l, r;
    std::cin >> l >> r;
    if (2*l <= r) {
      std::cout << l << " " << 2*l << std::endl;
    } else {
      std::cout << "-1 -1\n";
    }
  }
  return 0;
}
