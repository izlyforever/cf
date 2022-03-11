#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 2e5 + 2;

using Node = std::vector<std::pair<int, int>>;
Node f(const Node& a) {
  Node b;
  for (int i = 0, j, n = a.size(); i < n; i = j) {
    j = i + 1;
    while (j < n && a[j].first - a[j - 1].first <= 1) ++j;
    b.emplace_back(a[i].first, a[j - 1].first);
  }
  return b;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<Node> a(N), b(N);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    a[x].emplace_back(y, i);
  }
  for (auto &x : a) std::sort(x.begin(), x.end());
  for (int i = 0; i < N; ++i) if (!a[i].empty()) b[i] = f(a[i]);
  std::vector<int> ans(n, INT_MAX);
  std::vector<std::pair<int, int>> out(n);
  for (int i = 0; i < N; ++i) if (!a[i].empty()) {
    for (auto &[x, id] : a[i]) {
      auto& ansx = ans[id];
      auto& outx = out[id];
      for (int j = i; j >= 0; --j) {
        if (ansx <= i - j) break;
        auto it = std::upper_bound(b[j].begin(), b[j].end(), std::make_pair(x, INT_MAX));
        if (it == b[j].begin() || (--it)->second < x) {
          ansx = i - j;
          outx = {j, x};
        } else {
          int tmpl = i - j + x - it->first + 1;
          if (tmpl < ansx) {
            ansx = tmpl;
            outx = {j, it->first - 1};
          }
          int tmpr = i - j + it->second - x + 1;
          if (tmpr < ansx) {
            ansx = tmpr;
            outx = {j, it->second + 1};
          }
        }
      }
      for (int j = i + 1; j < N; ++j) {
        if (ansx <= j - i) break;
        auto it = std::upper_bound(b[j].begin(), b[j].end(), std::make_pair(x, INT_MAX));
        if (it == b[j].begin() || (--it)->second < x) {
          ansx = j - i;
          outx = {j, x};
        } else {
          int tmpl = j - i + x - it->first + 1;
          if (tmpl < ansx) {
            ansx = tmpl;
            outx = {j, it->first - 1};
          }
          int tmpr = j - i + it->second - x + 1;
          if (tmpr < ansx) {
            ansx = tmpr;
            outx = {j, it->second + 1};
          }
        }
      }
    }
  }
  for (auto &[x, y] : out) std::cout << x << ' ' << y << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
