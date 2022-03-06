#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    auto [x, y] = std::minmax(a[i], b[i]);
    l = std::max(l, x);
    r = std::max(r, y);
  }
  std::cout << 1LL * l * r << '\n';
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
