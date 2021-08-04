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
    if (m == 1) {
      std::cout << n + 1 << '\n';
    } else if (m == n) {
      std::cout << 2 << '\n';
    } else {
      std::cout << 3 << '\n';
    }
  }
  return 0;
}