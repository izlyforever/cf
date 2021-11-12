#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
bool solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> a(m);
  for (auto& [x, y] : a) std::cin >> y >> x;
  a.emplace_back(0, 1);
  std::sort(a.begin(), a.end());
  int now = 3;
  for (int i = 1; i <= m; ++i) {
    if (int it = (a[i].first - a[i - 1].first); it > 0) {
      if (i < m && a[i].first == a[i + 1].first) {
        if (now != 3) return false;
      } else {
        if (it % 2 == 1) {
          if (now == a[i].second) return false;
          if (now == 3) now = 3 - a[i].second;
          else now = 3;
        } else {
          if (now == 3 - a[i].second) return false;
          if (now == 3) now = 3 - a[i].second;
          else now = 3;
        }
      }
    }
  }
  return now == 3;
}
bool solve1() {
  int n, m;
  std::cin >> n >> m;
  // 没有注意到 n < 1e9...
  std::vector<std::vector<int>> a(2, std::vector<int>(n));
  for (int i = 0, r, c; i < m; ++i) {
    std::cin >> r >> c;
    a[--r][--c] = 1;
  }
  int now = 2;
  for (int i = 0; i < n; ++i) {
    if (a[0][i] + a[1][i] == 2) {
      if (now != 2) return false;
    } else if (a[0][i] + a[1][i] == 0) {
      if (now != 2) now = 1 - now;
    } else {
      int t = (a[1][i] == 1); // a[t][i] == 1
      if (now == t) return false;
      if (now == 2) now = 1 - t;
      else now = 2;
    }
  }
  return now == 2;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}