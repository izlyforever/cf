#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int t = (a + b + c) % 9, x = (a + b + c) / 9;
    std::cout << (t == 0 && a >= x && b >= x && c >= x ? "YES" : "NO") << std::endl;
  }
  return 0;
}