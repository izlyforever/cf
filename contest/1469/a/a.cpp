#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
bool solve() {
  std::string s;
  std::cin >> s;
  if (s.size() % 2) return 0;
  return s[0] != ')' && s.back() != '(';
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << std::endl;
  }
  return 0;
}
