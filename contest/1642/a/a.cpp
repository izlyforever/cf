#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::vector<std::pair<int, int>> a(3);
  for (auto &[x, y] : a) std::cin >> y >> x;
  std::sort(a.begin(), a.end());
  if (a[2].first == a[1].first) {
    std::cout << abs(a[1].second - a[2].second) << '\n';
  } else {
    std::cout << 0 << '\n';
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
