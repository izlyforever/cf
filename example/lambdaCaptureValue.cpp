#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int x = 0;
  auto f = [x]() mutable -> int {
    return --x;
  };
  auto g = [x]() -> int {
    return x;
  };
  ++x; // x 再次改变不会影响 f 和 g 中的 x
  cerr(f()); // -1
  cerr(g()); // 0
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  solve();
  return 0;
}
