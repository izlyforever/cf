#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::string s;
    std::cin >> s;
    int a = 0, b = 0, r = 0;
    for (auto c : s) {
      if (c == '(') ++a;
      if (c == ')') {
        if (a > 0) {
          --a;
          ++r;
        }
      }
      if (c == '[') ++b;
      if (c == ']') {
        if (b > 0) {
          --b;
          ++r;
        }
      }
    }
    std::cout << r << std::endl;
  }
  return 0;
}