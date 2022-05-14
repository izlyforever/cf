#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  LL n;
  std::cin >> n;
  if (n % 2 == 1 || n == 2) {
    std::cout << -1 << '\n';
  } else {
    n /= 2;
    std::cout << n / 3 + (n % 3 != 0) << ' ' << n / 2 << '\n';
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
