#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::string s;
    std::cin >> s;
    int n = s.size(), i = 0, lst = 0;
    LL ans = 0;
    while (i < n && s[i] == '?') ++i;
    if (i == n) ans = 1LL * n * (n + 1);
    while (i < n) {
      bool flag = (i % 2)^(s[i] == '0');
      int cnt = 0, j = i - 1;
      while (j >= 0 && s[j] == '?') ++cnt, --j;
      ++j;
      if (j) ans -= 1LL * cnt * (cnt + 1);
      while (i < n && (s[i] == '?' || ((s[i] == '0') ^ (i % 2)) == flag)) ++i;
      ans += 1LL * (i - j) * (i - j + 1);
    }
    std::cout << ans / 2 << '\n';
  }
  return 0;
}