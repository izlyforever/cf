#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  LL a, b;
  std::cin >> a >> b;
  if (a > b) std::swap(a, b);
  LL x = b - a;
  if (x == 0) {
    std::cout << "0 0\n";
  } else {
    std::cout << x << ' ' << std::min(a % x, x - a % x) << '\n';
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
