#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  for (int i = 0; i < s.size(); ++i) if (s[i] != s[0]) {
    std::cout << "2\n";
    return 0;
  }
  std::cout << "-1\n";
  return 0;
}