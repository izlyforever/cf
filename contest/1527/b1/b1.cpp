#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    if (n % 2 == 0 || s[n / 2] == '1' || std::count(s.begin(), s.end(), '0') == 1) {
      std::cout << "BOB\n";
    } else {
      std::cout << "ALICE\n";
    }
  }
  return 0;
}