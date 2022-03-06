#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    int a = n / 2020, b = n % 2020;
    std::cout << (a >= b ? "YES\n" : "NO\n");
  }
  return 0;
}
