#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::vector<int> solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(n + 1), pos(n + 1);
  std::vector<std::vector<int>> e(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    std::cin >> b[i];
    pos[b[i]] = i;
    if (a[i] != b[i]) e[b[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) if (!e[i].empty()) pos[i] = e[i][0];
  std::vector<int> c(m);
  for (auto& x : c) std::cin >> x;
  std::vector<int> r;
  for (int i = 0; i < m; ++i) {
    int x = c[i];
    if (!e[x].empty()) {
      r.emplace_back(e[x].back());
      e[x].pop_back();
    } else {
      if (pos[x]) {
        r.emplace_back(pos[x]);
      } else if (i != m - 1) {
        r.emplace_back(pos[c.back()]);
      } else {
        return std::vector<int>();
      }
    }
  }
  for (int i = 1; i <= n; ++i) if (!e[i].empty()) return std::vector<int>();
  return r;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    auto r = solve();
    int m = r.size();
    if (m > 0) {
      std::cout << "YES\n";
      for (auto x : r) std::cout << x << " ";
      std::cout << "\n";
    } else std::cout << "NO\n";
  }
  return 0;
}
