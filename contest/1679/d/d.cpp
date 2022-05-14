#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  LL k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    g[--x].emplace_back(--y);
  }
  auto f = [&](int x) {
    std::vector<std::vector<int>> e(n);
    std::vector<int> d(n);
    for (int u = 0; u < n; ++u) if (a[u] <= x) {
      for (auto v : g[u]) if (a[v] <= x) {
        e[u].emplace_back(v);
        ++d[v];
      }
    }
    std::vector<int> val(n);
    for (int i = 0; i < n; ++i) val[i] = (a[i] <= x);
    std::queue<int> Q;
    for (int i = 0; i < n; ++i) if (d[i] == 0) {
      Q.push(i);
    }
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      for (auto v : e[u]) {
        val[v] = std::max(val[v], val[u] + 1);
        if (--d[v] == 0) {
          Q.push(v);
        }
      }
    }
    if (std::count(d.begin(), d.end(), 0) != n) return true;
    return *std::max_element(val.begin(), val.end()) >= k;
  };
  int mx = *std::max_element(a.begin(), a.end());
  if (!f(mx)) {
    std::cout << -1 << '\n';
    return;
  }
  int l = 1, r = mx;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (f(mid)) r = mid - 1;
    else l = mid + 1;
  }
  std::cout << l << '\n';
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
