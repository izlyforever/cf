#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::set<int>> a(n);
  int ans = n;
  auto add = [&](int u, int v) {
    a[u].emplace(v);
    if (a[v].empty() || *a[v].rbegin() < v) --ans;
    a[v].emplace(u);
  };
  auto sub = [&](int u, int v) {
    a[u].erase(v);
    a[v].erase(u);
    if (a[v].empty() || *a[v].rbegin() < v) ++ans;
  };
  while (m--) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    if (u < v) std::swap(u, v);
    add(u, v);
  }
  std::cin >> m;
  while (m--) {
    int op;
    std::cin >> op;
    if (op == 3) {
      std::cout << ans << '\n';
    } else {
      int u, v;
      std::cin >> u >> v;
      --u; --v;
      if (u < v) std::swap(u, v);
      if (op == 1) add(u, v);
      else sub(u, v);
    }
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