#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    int t = 1 + (n - 1)/4;
    for (int i = t; i < n; ++i) std::cout << 9;
    for (int i = 0; i < t; ++i) std::cout << 8;
    std::cout << std::endl;
  }
  return 0;
}