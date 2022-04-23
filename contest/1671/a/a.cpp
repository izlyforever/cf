#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string s;
  std::cin >> s;
  int now = 1;
  for (int i = 1, n = s.size(); i < n; ++i) {
    if (s[i] == s[i - 1]) {
      ++now;
    } else {
      if (now == 1) {
        std::cout << "NO\n";
        return;
      }
      now = 1;
    }
  }
  if (now == 1) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
