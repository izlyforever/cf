#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (k == 1) {
    std::cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      std::cout << i << '\n';
    }
  } else if (n % 2 == 0) {
    std::cout << "YES\n";
    for (int i = 0, x = 1, y = 2 * k; i < n; i += 2) {
      for (int j = x; j <= y; j += 2) {
        std::cout << j << ' ';
      }
      std::cout << '\n';
      for (int j = x + 1; j <= y; j += 2) {
        std::cout << j << ' ';
      }
      std::cout << '\n';
      x += 2 * k;
      y += 2 * k;
    }
  } else {
    std::cout << "NO\n";
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}