#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int x = 1 << std::__lg(n - 1);
  for (int i = 1; i < x; ++i) {
    std::cout << i << ' ';
  }
  std::cout << 0 << ' ';
  for (int i = x; i < n; ++i) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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
