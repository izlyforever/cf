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
    int n, x;
    std::cin >> n >> x;
    if (n <= 2) print(1);
    else print((n - 3) / x + 2);
  }
  return 0;
}