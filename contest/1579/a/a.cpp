#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string a;
  std::cin >> a;
  std::vector<int> x(3);
  for (auto c : a) ++x[c - 'A'];
  std::cout << (x[1] == x[0] + x[2] ? "YES" : "NO") << '\n';
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
