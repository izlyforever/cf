#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  int mx = INT_MIN, ai, aj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      std::cin >> x;
      if (x > mx) {
        ai = i;
        aj = j;
        mx = x;
      }
    }
  }
  std::cout << std::max({(ai + 1) * (aj + 1),
                         (ai + 1) * (m - aj),
                         (n - ai) * (aj + 1),
                         (n - ai) *(m - aj) }) << '\n';
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
