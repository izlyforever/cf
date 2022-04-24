#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  std::string s;
  std::cin >> s;
  int sa = 0;
  for (auto x : s) {
    sa += (x == 'A' ? 1 : -1);
    if (sa < 0) return false;
  }
  return s.back() == 'B';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO" ) << '\n';
  }
  return 0;
}
