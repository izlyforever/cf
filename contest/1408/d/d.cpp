#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> a(n), b(m), t;
  for (auto& [x, y] : a) std::cin >> x >> y;
  for (auto& [x, y] : b) std::cin >> x >> y;
  std::vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i].first <= b[j].first && a[i].second <= b[j].second) {
        t.push_back({b[j].first - a[i].first + 1, b[j].second - a[i].second + 1});
      }
    }
  }
  std::sort(t.begin(), t.end());
  std::vector<int> mx(t.size() + 1);
  for (int i = t.size() - 1; ~i; --i) {
    mx[i] = std::max(mx[i + 1], t[i].second);
  }
  int ans = mx[0];
  for (int i = 0; i < t.size(); ++i) {
    ans = std::min(ans, mx[i + 1] + t[i].first);
  }
  print(ans);
  return 0;
}
