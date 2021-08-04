#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> e(n);
    for (int i = 0, u, v; i < m; ++i) {
      std::cin >> u >> v;
      --u;
      --v;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    std::vector<int> val(n, -1);
    val[0] = 0;
    std::queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      if (val[u] == 0) {
        for (auto v : e[u]) {
          if (val[v] == -1) {
            val[v] = 1;
            Q.push(v);
          } else val[v] = 1;
        }
      } else {
        for (auto v : e[u]) if (val[v] == -1) {
          val[v] = 0;
          Q.push(v);
        }
      }
    }
    if (*std::min_element(val.begin(), val.end()) == -1) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::vector<int> r;
      for (int i = 0; i < n; ++i) {
        if (val[i] == 0) r.emplace_back(i);
      }
      std::cout << r.size() << "\n";
      for (auto i : r) std::cout << i + 1 << " ";
      std::cout << "\n";
    }
  }
  return 0;
}