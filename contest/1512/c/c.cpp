#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int c[2];
    std::string s;
    std::cin >> c[0] >> c[1] >> s;
    int n = s.size();
    auto solve = [&]() -> bool {
      for (int i = 0; i < n; ++i) if (s[i] != '?') {
        if (s[n - 1 - i] == '?') {
          s[n - 1 - i] = s[i];
        } else if (s[i] != s[n - 1 - i]) return false;
      }
      for (int i = 0; i < n; ++i) if (s[i] != '?') --c[s[i] - '0'];
      if (c[0] < 0 || c[1] < 0) return false;
      if ((c[0] & 1) && (c[1] & 1)) return false;
      if (c[0] & 1) {
        s[n / 2] = '0';
        --c[0];
      }
      if (c[1] & 1) {
        s[n / 2] = '1';
        --c[1];
      }
      for (int i = 0; i < n; ++i) if (s[i] == '?' && i != n - 1 - i) {
        if (c[0] > 0) {
          c[0] -= 2;
          s[i] = s[n - 1 - i] = '0';
        } else {
          c[1] -= 2;
          s[i] = s[n - 1 - i] = '1';
        }
      }
      return true;
    };
    if (solve()) std::cout << s << '\n';
    else std::cout << -1 << '\n';
  }
  return 0;
}