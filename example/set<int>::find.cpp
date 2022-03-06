#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  LL x = 998244353;
  x *= x;
  std::set<int> S;
  S.insert(x);
  if (!S.count(x)) {
    std::cerr << "What the fuck" << '\n';
  }
  cerr(x);
  cerr(*S.begin());
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
