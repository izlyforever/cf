#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<LL> a(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    LL x;
    std::cin >> x;
    a[i] += a[i - 1] - x;
  }
  std::vector<std::vector<int>> e(n + 1);
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    e[l - 1].emplace_back(r);
    e[r].emplace_back(l - 1);
  }
  std::set<int> S;
  std::queue<int> Q;
  for (int i = 1; i <= n; ++i) {
    if (a[i]) {
      S.insert(i);
    } else {
      Q.push(i);
    }
  }
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    for (auto v : e[u]) if (!S.count(v)) {
      auto [l, r] = std::minmax(v, u);
      auto it = S.upper_bound(l);
      while (it != S.end() && *it < r) {
        Q.push(*it);
        it = S.erase(it);
      }
    }
  }
  std::cout << (S.empty() ? "YES" : "NO") << '\n';
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
