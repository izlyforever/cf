#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// n % 2 == 0
bool f(int n, int m, int k) {
  if (k & 1) return false;
  if (m % 2 == 0) return true;
  return k * 2 <= n * (m - 1);
}
bool solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  if (n % 2 == 0) return f(n, m, k);
  return f(m, n, m * n / 2 - k);
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}