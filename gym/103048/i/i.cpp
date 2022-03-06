#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s, t;
  std::cin >> s >> t;
  int i = 0, n = s.size();
  for (auto x : t) {
    while (i < n && s[i] != x) ++i;
    if (i == n) {
      std::cout << "No\n";
      return 0;
    }
    ++i;
  }
  std::cout << "Yes\n";
  return 0;
}
