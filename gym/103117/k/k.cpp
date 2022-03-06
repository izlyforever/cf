#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
      for (int j = i; j <= n; j += k) {
        std::cout << j << ' ';
      }
    }
    std::cout << '\n';
  }
  return 0;
}
