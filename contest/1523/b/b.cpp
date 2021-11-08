#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    for (int i = 0, x; i < n; ++i) std::cin >> x;
    std::cout << 3 * n << '\n';
    for (int i = 1; i <= n; i += 2) {
      std::cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      std::cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      std::cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      std::cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
      std::cout << 2 << ' ' << i << ' ' << i + 1 << '\n';
      std::cout << 1 << ' ' << i << ' ' << i + 1 << '\n';
    }
  }
  return 0;
}