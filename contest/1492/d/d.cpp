#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int a, b, k;
  std::cin >> a >> b >> k;
  if (b == 1) {
    if (k == 0) {
      std::cout << "Yes\n";
      std::cout << "1" << std::string(a, '0') << "\n";
      std::cout << "1" << std::string(a, '0') << "\n";
    } else {
      std::cout << "No\n";
    }
  } else {
    if (a == 0) {
      if (k == 0) {
        std::cout << "Yes\n";
        std::cout << std::string(b, '1') << "\n";
        std::cout << std::string(b, '1') << "\n";
      } else {
        std::cout << "No\n";
      }
    } else if (k <= a + b - 2) {
      std::cout << "Yes\n";
      std::string x(a + b, '0'), y(a + b, '0');
      x[0] = y[0] = '1';
      x[a + b - k - 1] = '1';
      y.back() = '1';
      int t = b - 2;
      for (int i = 1; t && i < a + b; ++i) if (i != a + b - k - 1) {
        x[i] = y[i] = '1';
        --t;
      }
      std::cout << x << "\n";
      std::cout << y << "\n";
    } else {
      std::cout << "No\n";
    }
  }
  return 0;
}
