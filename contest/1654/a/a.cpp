#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int mx = INT_MIN, mx2 = INT_MIN;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x >= mx) {
      mx2 = mx;
      mx = x;
    } else if (x > mx2) {
      mx2 = x;
    }
  }
  std::cout << mx + mx2 << '\n';
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
