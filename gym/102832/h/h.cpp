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
          Q.push(v);
        }
      }
    }
    return h[t] != -1;
  }
  // f 表示从 u 点出发拥有的最大流量，输出的是 u 到 t 的最大流量
  int dfs(int u, int t, int f) {
    if (u == t || f == 0) return f;
    int r = f;
    for (int& i = cur[u]; i < g[u].size(); ++i) {
      int j = g[u][i];
      auto [v, c] = e[j];
      if (c > 0 && h[v] == h[u] + 1) {
        int a = dfs(v, t, std::min(r, int(c)));
        e[j].second -= a;
        e[j ^ 1].second += a;
        r -= a;
        if (r == 0) return f;
      }
    }
    return f - r;
  }
 public:
  Dinic(int _n) : n(_n), g(n) {}
  void addEdge(int u, int v, int c) {
    if (u == v) return;
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

bool solve () {
  int nn, m, ss;
  std::cin >> nn >> m >> ss;
  int n = 1;
  for (int i = 0; i < nn; ++i) n *= 10;
  Dinic g(n + 2);
  int s = n, t = n + 1;
  std::vector<int> ban(n);
  for (int i = 0, x; i < m; ++i) {
    std::cin >> x;
    ban[x] = 1;
  }
  auto cal = [](int x) {
    int r = 0;
    while (x) {
      r += x % 10;
      x /= 10;
    }
    return r;
  };
  int cs = cal(ss);
  auto add = [&](int i, int t) {
    if (t % 2 != cs % 2) return;
    for (int j = 1; j < n; j *= 10) {
      // 往上移动一位
      if (i + j < n && cal(i + j) == t + 1) {
        if(!ban[i + j]) g.addEdge(i, i + j, 1);
      } else {
        if(!ban[i - 9 * j]) g.addEdge(i, i - 9 * j, 1);
      }
      // 往下移动一位
      if (i >= j && cal(i - j) == t - 1) {
        if (!ban[i - j]) g.addEdge(i, i - j, 1);
      } else {
        if (!ban[i + 9 * j]) g.addEdge(i, i + 9 * j, 1);
      }
    }
  };
  for (int i = 0; i < n; ++i) if (!ban[i]) {
    if (cal(i) % 2 == cs % 2) g.addEdge(s, i, 1);
    else g.addEdge(i, t, 1);
  }
  ban[ss] = 1;
  for (int i = 0; i < n; ++i) if (!ban[i]) {
    add(i, cal(i));
  }
  g.maxFlow(s, t);
  ban[ss] = 0;
  g.addEdge(s, ss, 1);
  add(ss, cs);
  return g.maxFlow(s, t);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Alice\n" : "Bob\n");
  }
  return 0;
}
