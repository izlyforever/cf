#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::set<char> S{s[0]};
  for (int i = 1; i < n; ++i) if (s[i] != s[i - 1]) {
    if (S.count(s[i])) return false;
    S.insert(s[i]);
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
