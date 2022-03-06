#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n, x;
  LL y;
  std::cin >> n >> x >> y;
  for (int i = 0; i < n; ++i) {
    int tmp;
    std::cin >> tmp;
    x ^= tmp;
  }
  return (x & 1) == (y & 1);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Alice" : "Bob") << '\n';
  }
  return 0;
}
