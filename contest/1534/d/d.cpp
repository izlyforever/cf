#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool

void solve() {
  int n;
  std::cin >> n;
  auto Q = [&](int u) -> std::vector<int> {
    std::cout << "? " << u + 1 << std::endl;
    std::vector<int> d(n);
    for (auto &x : d) std::cin >> x;
    return d;
  };
  auto d = Q(0);
  std::vector<int> p(n, -1);
  p[0] = 0;
  std::set<std::pair<int, int>> S;
  for (int i = 1; i < n; ++i) {
    if (d[i] == 1) p[i] = 0;
    S.insert({-d[i], i});
  }
  while (!S.empty()) {
    auto [du, u] = *S.begin();
    S.erase(S.begin());
    if (p[u] != -1) continue;
    du = -du;
    auto ds = Q(u);
    std::vector<int> sz(du + 1);
    for (int i = 0; i < n; ++i) {
      if (d[i] + ds[i] == du) sz[ds[i]] = i;
    }
    for (int i = 0; i < n; ++i) if (ds[i] == 2 && sz[ds[i]] != i) {
      p[i] = sz[1];
    }
    for (int i = 0; i < du; ++i) p[sz[i]] = sz[i + 1];
  }
  std::cout << "!" << std::endl;
  for (int i = 1; i < n; ++i) std::cout << p[i] + 1 << ' ' << i + 1 << '\n';
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