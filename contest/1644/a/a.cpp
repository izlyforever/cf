#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  std::string s;
  std::cin >> s;
  std::set<char> S;
  for (int i = 0; i < 6; ++i) {
    if (s[i] <= 'z' && s[i] >= 'a') {
      S.insert(char(s[i] - 32));
    } else if (!S.count(s[i])) {
      return false;
    }
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}