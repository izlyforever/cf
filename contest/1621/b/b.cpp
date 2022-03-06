#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int l, r = INT_MIN, c, cl, cr;
  l = c = cl = cr = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int li, ri, ci;
    std::cin >> li >> ri >> ci;
    if (li < l || ri > r) c = INT_MAX;
    if (li < l || (li == l && ci < cl)) {
      l = li;
      cl = ci;
    }
    if (ri > r || (ri == r && ci < cr)) {
      r = ri;
      cr = ci;
    }
    if (li == l && ri == r) c = std::min(c, ci);
    std::cout << std::min(c, cl + cr) << '\n';
  }
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
