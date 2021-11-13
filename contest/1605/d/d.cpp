#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  std::vector<int> val(n + 1, -1);
  val[1] = 1;
  std::queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : e[u]) if (val[v] == -1) {
      val[v] = 1 - val[u];
      Q.push(v);
    }
  }
  std::vector<int> cnt[2];
  for (int i = 1; i <= n; ++i) cnt[val[i]].emplace_back(i);
  std::vector<int> ans(n + 1);
  std::vector<std::pair<int, int>> a;
  int t = 1;
  while ((1 << t) <= n) {
    a.emplace_back(1 << t - 1, (1 << t) - 1);
    ++t;
  }
  a.emplace_back(n - (1 << t - 1) + 1, n);
  std::sort(a.begin(), a.end());
  while (!cnt[0].empty() || !cnt[1].empty()) {
    bool flag = cnt[1].size() > cnt[0].size();
    int now = a.back().second;
    for (int i = a.back().first; i > 0; --i) {
      ans[cnt[flag].back()] = now--;
      cnt[flag].pop_back();
    }
    a.pop_back();
  }
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
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
