#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 1e6 + 2;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int x;
    std::cin >> x;
    int r = 1;
    while (r * (r + 1) / 2 < x) ++ r;
    if (r * (r + 1) / 2 == x + 1) ++r;
    std::cout << r << std::endl;
  }
  return 0;
}