#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    if (n & 1) {
      int now = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          std::cout << now << " ";
          now = -now;
        }
      }
    } else {
      int now = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          if (i % 2 == 0 && j == i + 1) {
            std::cout << "0 ";
          } else {
            std::cout << now << " ";
            now = -now;
          }
        }
        now = -now;
      }
    }
    std::cout << "\n";
  }
  return 0;
}
