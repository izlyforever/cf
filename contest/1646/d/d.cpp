#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::set<int>> e(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    e[u].insert(v);
    e[v].insert(u);
  }
  auto g = e;

  std::vector<int> val(n);
  std::set<int> S;
  for (int i = 0; i < n; ++i) S.insert(i);
  std::priority_queue<std::pair<int, int>> Q;
  std::vector<int> a;
  a.reserve(n);
  while (!S.empty()) {
    for (auto x : S) if (e[x].size() <= 1) {
      if (e[x].empty()) {
        a.emplace_back(x);
        if (val[x]) continue;
        for (auto y : g[x]) val[x] += val[y];
      } else {
        Q.push({e[x].size() - g[x].size(), x});
      }
    }
    for (auto x : a) S.erase(x);
    a.clear();
    while (!Q.empty()) {
      auto [cu, u]  = Q.top();
      Q.pop();
      if (val[u] || e[u].empty()) continue;
      auto v = *e[u].begin();
      for (auto x : e[v]) {
        e[x].erase(v);
      }
      e[v].clear();
      val[v] = 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int sm = 0;
    for (auto x : g[i]) sm += val[x];
    if (sm == val[i]) ++cnt;
  }
  std::cout << cnt << ' ' << std::accumulate(val.begin(), val.end(), 0) << '\n';
  for (int i = 0; i < n; ++i) {
    std::cout << val[i] << ' ';
  }
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
