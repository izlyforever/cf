#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (n == 4 && k == 3) {
    std::cout << -1 << '\n';
  } else if (k != n - 1) {
    std::cout << 0 << ' ' << n - 1 - k << '\n';
    if (k != 0) {
      std::cout << k << ' ' << n - 1 << '\n';
    }
    for (int i = 1; i < n / 2; ++ i) if (i != k && i != n - 1 - k) {
      std::cout << i << ' ' << n - 1 - i << '\n';
    }
  } else {
    std::cout << 1 << ' ' << 3 << '\n';
    std::cout << n - 2 << ' ' << n - 1 << '\n';
    std::cout << 2 << ' ' << n - 3 << '\n';
    std::cout << 0 << ' ' << n - 4 << '\n';
    for (int i = 4; i < n / 2; ++i) {
      std::cout << i << ' ' << n - 1 - i << '\n';
    }
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
