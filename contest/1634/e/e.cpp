#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int m, n = 0;
  std::cin >> m;
  std::vector<std::vector<int>> a(m);
  std::map<int, int> mp;
  for (int i = 0; i < m; ++i) {
    int sz;
    std::cin >> sz;
    a[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      std::cin >> a[i][j];
      ++mp[a[i][j]];
    }
    n += sz;
  }
  for (auto [x, c] : mp) if (c & 1) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";

  std::vector<std::pair<int, int>> pos;
  pos.reserve(n);
  std::vector<std::vector<int>> sob(m);
  std::vector<std::string> ans(m);
  for (int i = 0; i < m; ++i) {
    int sz = a[i].size();
    ans[i] = std::string(sz, 'M');
    sob[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      sob[i][j] = pos.size();
      pos.emplace_back(i, j);
    }
  }

  int p = 0;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    it->second = m + p;
    ++p;
  }

  std::vector<std::pair<int, int>> edge;
  std::vector<std::set<int>> e(m + p);
  for (int i = 0; i < m; ++i) {
    int sz = a[i].size();
    for (int j = 0; j < sz; ++j) {
      int k = mp[a[i][j]];
      e[i].emplace(edge.size());
      e[k].emplace(edge.size());
      edge.emplace_back(i, k);
    }
  }
  std::function<void(int)> Hierholzer = [&](int u) {
    while (!e[u].empty()) {
      int it = *e[u].begin();
      auto [i, j] = pos[it];
      if (u < m) {
        ans[i][j] = 'L';
      } else {
        ans[i][j] = 'R';
      }
      int v = -u + edge[it].first + edge[it].second;
      e[u].erase(it);
      e[v].erase(it);
      Hierholzer(v);
    }
  };
  for (int i = 0; i < m; ++i) {
    if (!e[i].empty()) {
      Hierholzer(i);
    }
  }
  for (auto &x : ans) std::cout << x << '\n';
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