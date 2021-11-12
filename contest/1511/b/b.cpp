#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  std::vector<int> ten(10, 1);
  for (int i = 1; i < 10; ++i) ten[i] = ten[i - 1] * 10;
  auto f = [&](int a, int b, int c) -> std::pair<int, int> {
    return {(ten[a - c] + 1) * ten[c - 1], ten[b - 1]};
  };
  while (cas--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a >= b) {
      auto [x, y] = f(a, b, c);
      std::cout << x << ' ' << y << '\n';
    } else {
      auto [y, x] = f(b, a, c);
      std::cout << x << ' ' << y << '\n';
    }
  }
  return 0;
}