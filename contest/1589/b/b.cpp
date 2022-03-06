#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n, m;
  std::cin >> n >> m;
  if (n % 3 == 0) return n / 3 * m;
  if (m % 3 == 0) return m / 3 * n;
  if (n % 3 == 1) return n / 3 * m + m / 3 + 1;
  if (m % 3 == 1) return m / 3 * n + n / 3 + 1;
  return m / 3 * n + n / 3 * 2 + 2;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
