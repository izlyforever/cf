#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int q;
  std::cin >> q;
  std::map<int, std::vector<int>> pos;
  int n = 0;
  while (q--) {
    int op, x, y;
    std::cin >> op >> x;
    if (op == 1) {
      pos[x].emplace_back(n++);
    } else {
      std::cin >> y;
      if (x == y) continue;
      if (pos[x].size() > pos[y].size()) {
        pos[x].insert(pos[x].end(), pos[y].begin(), pos[y].end());
        pos[y].clear();
        std::swap(pos[x], pos[y]);
      } else {
        pos[y].insert(pos[y].end(), pos[x].begin(), pos[x].end());
        pos[x].clear();
      }
    }
  }
  std::vector<int> ans(n);
  for (auto &[x, p] : pos) {
    for (auto id : p) ans[id] = x;
  }
  for (auto &x : ans) std::cout << x << ' ';
  std::cout << '\n';
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
