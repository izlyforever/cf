#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;


bool solve() {
  std::string s;
  std::cin >> s;
  int l = 0, r = s.size() - 1, x = r;
  while (l <= r) {
    if (s[l] - 'a' == x) {
      ++l;
    } else if (s[r] - 'a' == x) {
      --r;
    } else return false;
    --x;
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