#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

class Flow {
  static inline constexpr LL INF = INT64_MAX >> 1;
  int n;
  // e[i] = {endPoint, conpacity} and e[i ^ 1] is opposite edge of e[i]
  // g[u] = {edges start from u}
  std::vector<std::tuple<int, int, int>> e;
  std::vector<std::vector<int>> g;
  std::vector<int> path;
  std::vector<LL> h;
  // h[i] = dist(s, i), h[t] != -1 means there is a path from s to t, and h[t] will be the potential.
  // path[v]: short path form s to v, path[v] is the previous node of v
  bool Dijkstra(int s, int t) {
    std::priority_queue<std::pair<LL, int>> Q;
    std::fill(path.begin(), path.end(), -1);
    std::vector<LL> d(n, INF);
    d[s] = 0;
    Q.push({0, s});
    while (!Q.empty()) {
      auto [du, u] = Q.top();
      Q.pop();
      if (d[u] != -du) continue;
      for (auto i : g[u]) {
        auto [v, w, c] = e[i];
        c += h[u] - h[v];
        if (w > 0 && d[v] > d[u] + c) {
          d[v] = d[u] + c;
          path[v] = i;
          Q.push({-d[v], v});
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if ((h[i] += d[i]) > INF) h[i] = INF;
    }
    return h[t] != INF;
  }
public:
  Flow(int _n) : n(_n), g(n), h(n), path(n) {}
  void addEdge(int u, int v, int w, int c) {
    if (u == v) return;
    g[u].emplace_back(e.size());
    e.emplace_back(v, w, c);
    g[v].emplace_back(e.size());
    e.emplace_back(u, 0, -c);
  }
  std::pair<LL, LL> maxFlow(int s, int t) {
    LL flow = 0, cost = 0;
    while (Dijkstra(s, t)) {
      int f = INT_MAX, now = t;
      std::vector<int> r;
      while (now != s) {
        r.emplace_back(path[now]);
        f = std::min(f, std::get<1>(e[path[now]]));
        now = std::get<0>(e[path[now] ^ 1]);
      }
      for (auto i : r) {
        std::get<1>(e[i]) -= f;
        std::get<1>(e[i ^ 1]) += f;
      }
      flow += f;
      cost += LL(f) * h[t];
    }
    return {flow, cost};
  }
};


// 根据情况换成 bool
void solve() {
  const int MAX = 1e9 + 1;
  int n, a, b, c;
  std::cin >> n >> a >> b >> c;
  Flow A(n + 5);
  for (int i = 1; i <= n; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    A.addEdge(i, 0, 1, 0);
    A.addEdge(n + 1, i, 1, MAX - x);
    A.addEdge(n + 2, i, 1, MAX - y);
    A.addEdge(n + 3, i, 1, MAX - z);
  }
  A.addEdge(n + 4, n + 1, a, 0);
  A.addEdge(n + 4, n + 2, b, 0);
  A.addEdge(n + 4, n + 3, c, 0);
  auto [flow, cost] = A.maxFlow(n + 4, 0);
  assert(flow == n);
  std::cout << 1LL * MAX * n - cost << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}