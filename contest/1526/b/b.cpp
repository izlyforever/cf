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
    int x = n / 11, y = n - 11 * x;
    std::cout << (x >= 10 * y ? "YES" : "NO") << '\n';
  }
  return 0;
}