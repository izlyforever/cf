#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int a, b;
    std::cin >> a >> b;
    int c = abs(a - b);
    std::cout << (c + 9) / 10 << std::endl;
  }
  return 0;
}
