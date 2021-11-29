#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto& x : a) std::cin >> x;
  for (auto& x : b) std::cin >> x;
  for (int i = 0; i < n; ++i) a[i] -= b[i];
  if (std::accumulate(a.begin(), a.end(), 0) == 0) {
    std::vector<std::pair<int, int>> x, y, ans;
    for (int i = 0; i < n; ++i) {
      if (a[i] > 0) x.emplace_back(a[i], i + 1);
      else if (a[i] < 0) y.emplace_back(-a[i], i + 1);
    }
    while (!x.empty()) {
      ans.emplace_back(x.back().second, y.back().second);
      if (--x.back().first == 0) x.pop_back();
      if (--y.back().first == 0) y.pop_back();
    }
    std::cout << ans.size() << '\n';
    for (auto [x, y] : ans) std::cout << x << ' ' << y << '\n';
  } else {
    std::cout << -1 << '\n';
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