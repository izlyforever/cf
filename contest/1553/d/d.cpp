#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

bool solve() {
  std::string s, t;
  std::cin >> s >> t;
  int n = s.size(), i = n - 1;
  while (!t.empty()) {
    while (i >= 0 && (s[i] != t.back() || (n - i) % 2 == 0)) --i;
    if (i < 0) return false;
    std::cerr << i << s[i] << ' ' << t.back() << '\n';
    t.pop_back();
    n = i;
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