#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i].first;
  for (int i = 0; i < n; ++i) std::cin >> a[i].second;
  std::sort(a.begin(), a.end());
  for (auto [x, y] : a) {
    if (x > k) break;
    k += y;
  }
  std::cout << k << '\n';
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
