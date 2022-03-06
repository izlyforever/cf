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
    int i = 0;
    while (i < s.size() && s[i] == 'a') ++i;
    if (i == s.size()) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      s.insert(s.begin() + s.size() - i, 'a');
      std::cout << s << '\n';
    }
  }
  return 0;
}
