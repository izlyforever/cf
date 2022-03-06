#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string s;
  std::cin >> s;
  int it = std::min_element(s.begin(), s.end()) - s.begin();
  std::cout << s[it] << ' ';
  for (int i = 0, n = s.size(); i < n; ++i) if (i != it) {
    std::cout << s[i];
  }
  std::cout << '\n';
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
