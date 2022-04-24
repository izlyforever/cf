#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), cnt(n);
  for (auto &x : a) {
    std::cin >> x;
    ++cnt[--x];
  }
  for (auto &x : b) {
    std::cin >> x;
    --x;
  }
  int x = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
  std::vector<std::vector<int>> e(n);
  for (int i = 0; i < n; ++i) {
    e[a[i]].emplace_back(b[i]);
  }
  std::vector<int> path;
  std::function<void(int, int)> dfs = [&](int u, int fa) {
    while (!e[u].empty()) {
      int v = e[u].back();
      e[u].pop_back();
      dfs(v, u);
    }
    if (fa != -1) {
      path.emplace_back(fa);
    }
  };
  dfs(x, -1);
  if (path.size() != n) {
    std::cout << "WA\n";
    return;
  }

  std::vector<std::vector<int>> g(n);
  std::vector<int> deg(n);
  for (int i = 1; i < n; ++i) {
    if (path[i - 1] != x) {
      g[path[i]].emplace_back(path[i - 1]);
      ++deg[path[i - 1]];
    }
  }
  std::queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) Q.push(i);
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : g[u]) {
      if (--deg[v] == 0) Q.push(v);
    }
  }
  int nz = std::count(deg.begin(), deg.end(), 0);
  std::cout << (nz == n ? "AC" : "WA") << '\n';
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
