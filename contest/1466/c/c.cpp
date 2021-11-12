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
    int r = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        for (char t = 'a'; t <= 'z'; ++t) {
          if (t != s[i] && t != s[i - 1] && (i < 2 || t != s[i - 2]) && (i + 1 > s.size() || t != s[i + 1]) && (i + 2 > s.size() || t != s[i + 2])) {
            s[i] = t;
            break;
          }
        }
        ++r;
      } else if (i > 1 && s[i] == s[i - 2]) {
        for (char t = 'a'; t <= 'z'; ++t) {
          if (t != s[i] && t != s[i - 1] && t != s[i - 2] && (i + 1 > s.size() || t != s[i + 1]) && (i + 2 > s.size() || t != s[i + 2])) {
            s[i] = t;
            break;
          }
        }
        ++r;
      }
    }
    std::cout << r << std::endl;
  }
  return 0;
}