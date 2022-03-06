#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

struct  Node {
  int a, b, c, d, h;
};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> cost(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> cost[i];
  std::vector<Node> ladder(k);
  int id = 0;
  std::vector<std::vector<int>> e(n + 1);
  for (auto &[a, b, c, d, h] : ladder) {
    std::cin >> a >> b >> c >> d >> h;
    e[a].emplace_back(id);
    ++id;
  }
  const LL INF = INT64_MAX / 2;
  std::vector<std::vector<std::pair<int, LL>>> g(n + 1);
  g[1].emplace_back(1, 0);
  LL ans = INF;
  for (int i = 1; i <= n; ++i) if (!g[i].empty()) {
    auto& gi = g[i];
    std::sort(gi.begin(), gi.end());
    int gni = gi.size();
    std::vector<LL> gl(gni), gr(gni);
    LL nl = INF;
    for (int j = 0; j < gni; ++j) {
      nl = std::min(nl, gi[j].second - 1LL * gi[j].first * cost[i]);
      gl[j] = nl;
    }
    LL nr = INF;
    for (int j = gni - 1; j >= 0; --j) {
      nr = std::min(nr, gi[j].second + 1LL * gi[j].first * cost[i]);
      gr[j] = nr;
    }
    for (auto x : e[i]) {
      auto [a, b, c, d, h] = ladder[x];
      LL tmp = INF;
      auto id = std::lower_bound(gi.begin(), gi.end(), std::make_pair(b, 0LL)) - gi.begin();
      if (id < gni) {
        tmp = std::min(tmp, gr[id] - 1LL * b * cost[a]);
      }
      if (id > 0) {
        tmp = std::min(tmp, gl[id - 1] + 1LL * b * cost[a]);
      }
      g[c].emplace_back(d, tmp - h);
    }
    if (i == n) {
      ans = gl.back() + 1LL * m * cost[n];
    }
  }
  if (ans == INF) {
    std::cout << "NO ESCAPE\n";
  } else {
    std::cout << ans << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
