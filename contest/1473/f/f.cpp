#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

class Dinic {
  int n;
  // e[i] 表示第 i 条边的终点和容量，注意存边的时候 e[i ^ 1] 是 e[i] 的反向边。
  // g[u] 存的是所有以 u 为起点的边，这就很像链式前向星的做法
  std::vector<std::pair<int, int>> e;
  std::vector<std::vector<int>> g;
  std::vector<int> cur, h;
  // h[i] 表示 bfs 从 s 到 i 的距离，如果找到了 t，那么就说明找到了增广路。
  bool bfs(int s, int t) {
    h.assign(n, -1);
    std::queue<int> Q;
    h[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto i : g[u]) {
        auto [v, c] = e[i];
        if (c > 0 && h[v] == -1) {
          h[v] = h[u] + 1;
          if (v == t) return true;
          Q.push(v);
        }
      }
    }
    return false;
  }
  // f 表示从 u 点出发拥有的最大流量，输出的是 u 到 t 的最大流量
  int dfs(int u, int t, int f) {
    if (u == t) return f;
    int r = f;
    for (int &i = cur[u]; i < g[u].size(); ++i) {
      int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        int a = dfs(v, t, std::min(r, c));
        e[j].second -= a;
        e[j ^ 1].second += a;
        r -= a;
        if (r == 0) return f;
      }
    }
    return f - r;
  }
 public:
  Dinic(int _n) : n(_n), g(_n) {}
  void addEdge(int u, int v, int c) {
    g[u].emplace_back(e.size());
    e.emplace_back(v, c);
    g[v].emplace_back(e.size());
    e.emplace_back(u, 0);
  }
  int maxFlow(int s, int t) {
    int r = 0;
    while (bfs(s, t)) {
      cur.assign(n, 0);
      r += dfs(s, t, INT_MAX);
    }
    return r;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  std::vector<int> last(101, -1);
  Dinic g(n + 2);
  int r = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] > 0) {
      r += b[i];
      g.addEdge(n, i, b[i]);
    } else {
      g.addEdge(i, n + 1, -b[i]);
    }
    for (int j = 1; j <= a[i]; ++j) {
      if (a[i] % j == 0 && last[j] != -1) {
        g.addEdge(i, last[j], INT_MAX);
      }
    }
    last[a[i]] = i;
  }
  r -= g.maxFlow(n, n + 1);
  std::cout << r << std::endl;
  return 0;
}
