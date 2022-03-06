#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
bool solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  if (s[0] == '2') {
    if (s[1] == '0') {
      if (s[2] == '2') {
        if (s[3] == '0') {
          return 1;
        }
        return s.back() == '0';
      }
      return s.substr(n - 2, n - 1) == "20";
    }
    return s.substr(n - 3, n - 1) == "020";
  }
  return s.substr(n - 4, n - 1) == "2020";
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
