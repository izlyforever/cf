#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
using pii = std::pair<int, int>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int m = 6;
  std::vector<int> a(m);
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  int n;
  std::cin >> n;
  std::vector<int> b(n);
  for (auto& x : b) std::cin >> x;
  std::vector<pii> p;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      p.push_back({b[j] - a[i], j});
    }
  }
  std::sort(p.begin(), p.end());
  std::vector<int> cnt(n);
  int r = 1e9 + 2;
  for (int i = 0, j = 0, x = 0; i < p.size(); ++i) {
    while (x < n && j < p.size()) {
      if (cnt[p[j].second] == 0) ++x;
      ++cnt[p[j].second];
      ++j;
    }
    if (x < n) break;
    if (--cnt[p[i].second] == 0) --x;
    r = std::min(r, p[j - 1].first - p[i].first);
  }
  print(r);
  return 0;
}