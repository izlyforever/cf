#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  auto vis = a;
  for (auto &x : a) for (auto&y : x) std::cin >> y;
  auto check = [&](int x, int y) -> int {
    if (x < 0 || y < 0 || x >= n - 1 || y >= m - 1) return -1;
    std::vector<int> tmp{a[x][y], a[x][y + 1], a[x + 1][y], a[x + 1][y + 1]};
    std::sort(tmp.begin(), tmp.end());
    for (int i = 2; i >= 0; --i) if (tmp[i]) {
      if (tmp[i] != tmp.back()) return -1;
    }
    return tmp.back();
  };
  std::vector<std::tuple<int, int, int>> ans;
  std::queue<std::pair<int, int>> Q;
  auto Push = [&](int x, int y) {
    if (check(x, y) != -1 && !vis[x][y]) {
      vis[x][y] = true;
      Q.push({x, y});
    }
  };
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      Push(i, j);
    }
  }
  while (!Q.empty()) {
    auto [u, v] = Q.front();
    Q.pop();
    auto r = check(u, v);
    if (r) {
      ans.emplace_back(u, v, r);
      a[u][v] = a[u][v + 1] = a[u + 1][v] = a[u + 1][v + 1] = 0;
    }
    for (int i = 0; i < 2; ++i) {
      Push(u - 1, v + i);
      Push(u + i - 1, v - 1);
      Push(u + 1, v + i - 1);
      Push(u + i, v + 1);
    }
  }
  if ([&]() {
    for (int i = 0; i < n; ++i) {
      if (std::count(a[i].begin(), a[i].end(), 0) != m) return false;
    }
    return true;
  }()) {
    std::cout << ans.size() << '\n';
    std::reverse(ans.begin(), ans.end());
    for (auto& [x, y, z] : ans) {
      std::cout << x + 1 << ' ' << y + 1 << ' ' << z << '\n';
    }
  } else {
    std::cout << -1 << '\n';
  }
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