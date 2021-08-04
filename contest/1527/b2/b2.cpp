#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) if (s[i] == '0') {
      if (s[i] == s[n - 1 - i]) ++a;
      else ++b;
    }
    if (b == 0) {
      if (n % 2 == 0 || s[n / 2] == '1' || std::count(s.begin(), s.end(), '0') == 1) {
      std::cout << "BOB\n";
      } else {
        std::cout << "ALICE\n";
      }
    } else {
      if (a == 1 && b == 1) std::cout << "DRAW\n";
      else std::cout << "ALICE\n";
    }
  }
  return 0;
}