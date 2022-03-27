#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> c(n);
  for (auto &x : c) std::cin >> x;
  if (std::count(c.begin(), c.end(), 1) != 1) return false;
  for (int i = 1; i <= n; ++i) {
    if (c[i % n] > c[i - 1] + 1) return false;
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
