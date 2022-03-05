#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::set<int>> e(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u; --v;
    e[u].insert(v);
    e[v].insert(u);
  }
  using Node = std::array<std::pair<int, int>, 2>;
  std::vector<Node> dp(n);
  std::function<void(int, int)> pdfs = [&](int u, int fa) {
    for (auto v : e[u]) if (v != fa) {
      pdfs(v, u);
      auto [x, y] = std::max(dp[v][0], dp[v][1]);
      dp[u][0].first += x;
      dp[u][0].second += y;
      dp[u][1].first += dp[v][0].first;
      dp[u][1].second += dp[v][0].second;
    }
    dp[u][0].second -= 1;
    ++dp[u][1].first;
    dp[u][1].second -= e[u].size();
  };
  pdfs(0, 0);
  std::vector<int> a;
  a.reserve(n);
  std::function<void(int, int, int)> dfs = [&](int u, int fa, int t) {
    if (t == 1) {
      if (dp[u][1] >= dp[u][0]) {
        a.emplace_back(u);
      } else {
        t = 0;
      }
    }
    for (auto v : e[u]) if (v != fa) {
      dfs(v, u, 1 - t);
    }
  };
  dfs(0, 0, 1);
  std::vector<int> val(n, 1);
  for (auto x : a) val[x] = e[x].size();
  int cnt = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    if (val[i] == e[i].size()) ++cnt;
    sum += val[i];
  }
  std::cout << cnt<< ' ' << sum << '\n';
  for (int i = 0; i < n; ++i) {
    std::cout << val[i] << ' ';
  }
  std::cout << '\n';
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
