#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int mx = 0;
  LL sm = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    sm += x;
    mx = std::max(mx, x);
  }
  if (mx == 0) {
    std::cout << 0 << '\n';
    return;
  }
  if (mx <= sm - mx + 1) {
    std::cout << 1 << '\n';
  } else {
    std::cout << mx - (sm - mx) << '\n';
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
