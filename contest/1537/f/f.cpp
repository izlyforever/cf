#include <bits/stdc++.h>
using LL = long long;

bool solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  for (int i = 0, x; i < n; ++i) std::cin >> x, a[i] = x - a[i];
  std::vector<std::vector<int>> e(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    if (--u == --v) continue;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  std::vector<int> val(n, -1);
  for (int i = 0; i < n; ++i) if (val[i] == -1) {
    int ispart = true;
    std::queue<int> Q;
    Q.push(i);
    val[i] = 0;
    LL sum[2]{a[i], 0};
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto v : e[u]) {
        if (val[v] == -1) {
          val[v] = !val[u];
          sum[val[v]] += a[v];
          Q.push(v);
        } else {
          if (val[v] == val[u]) {
            ispart = false;
          }
        }
      }
    }
    bool flag = ispart ? sum[0] == sum[1] : ((sum[0] + sum[1]) % 2 == 0);
    if (!flag) return false;
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
