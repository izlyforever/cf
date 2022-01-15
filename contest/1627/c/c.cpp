#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> d(n);
  std::vector<std::vector<int>> e(n);
  std::vector<std::tuple<int, int, int>> edge(n - 1);
  int id = 0;
  for (auto& [x, y, z] : edge) {
    std::cin >> x >> y;
    --x; --y;
    e[x].emplace_back(id);
    e[y].emplace_back(id);
    ++id;
  }
  for (int i = 0; i < n; ++i) if (e[i].empty() || e[i].size() > 2) {
    std::cout << -1 << '\n';
    return;
  }
  id = 0;
  while (e[id].size() != 1) ++id;
  int now = 2;
  do {
    int i = e[id][0];
    auto& [x, y, z] = edge[i];
    z = now;
    id = x + y - id;
    e[id].erase(std::find(e[id].begin(), e[id].end(), i));
    now = 7 - now;
  } while (!e[id].empty());
  for (auto [x, y, z] : edge) std::cout << z << ' ';
  std::cout << '\n';
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