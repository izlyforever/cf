#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 2e5 + 2;
std::vector<int> bad[N];
void init() {
  for (int i = 1; i < N; ++i) {
    for (int j = i * 2; j < N; j += i) if ((j ^ i) == j - i){
      bad[j - i].emplace_back(j);
      bad[j].emplace_back(j - i);
    }
  }
  for (int i = 1; i < N; ++i) std::sort(bad[i].begin(), bad[i].end());
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int n, m;
  std::cin >> n >> m;
  std::vector<int> p(n + m + 1), a(n + m + 1);
  std::iota(p.begin(), p.end(), 0);
  std::vector<std::map<int, int>> mp(n + m + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    mp[i].insert({a[i], 1});
  }
  std::function<int(int)> find = [&](int x) ->int {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  };
  LL ans = 0;
  auto merge = [&](int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (mp[fx].size() < mp[fy].size()) std::swap(fx, fy);
    p[fy] = fx;
    for (auto [v, c] : mp[fy]) {
      for (auto t : bad[v]) if (mp[fx].count(t)) {
        ans += LL(mp[fx][t]) * c;
      }
    }
    for (auto [v, c] : mp[fy]) {
      mp[fx][v] += c;
    }
  };
  auto change = [&](int x, int y) {
    int fx = find(x);
    auto &it = mp[fx];
    for (auto t : bad[a[x]]) if (it.count(t)) {
      ans -= it[t];
    }
    --it[a[x]];
    for (auto t : bad[y]) if (it.count(t)) {
      ans += it[t];
    }
    ++it[y];
    a[x] = y;
  };
  for (int i = 0; i < m; ++i) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) {
      a[x] = y;
      mp[x].insert({y, 1});
    } else if (op == 2) {
      merge(x, y);
    } else if (a[x] != y) {
      change(x, y);
    }
    std::cout << ans << "\n";
  }
  return 0;
}