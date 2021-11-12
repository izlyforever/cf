#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL a, b;
    std::cin >> a >> b;
    if (b == 1) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::cout << a << ' ' << a * b << ' ' << a * (b + 1) << '\n';
    }
  }
  return 0;
}