#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, z;
  std::cin >> n >> z;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ans = std::max(ans, x | z);
  }
  std::cout << ans << '\n';
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
