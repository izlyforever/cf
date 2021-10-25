#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> now(n);
  for (auto &x : now) std::cin >> x;
  std::vector<std::vector<int>> a{std::move(now)};
  while (1) {
    auto& cur = a.back();
    std::vector<int> cnt(n + 1);
    for (auto x : cur) ++cnt[x];
    std::vector<int> now;
    now.reserve(n);
    bool ok = true;
    for (auto x : cur) now.emplace_back(cnt[x]);
    for (int i = 0; i < n; ++i) if (cur[i] != now[i]) {
      ok = false;
      break;
    }
    if (ok) break;
    a.emplace_back(std::move(now));
  }
  int q;
  std::cin >> q;
  while (q--) {
    int x, k;
    std::cin >> x >> k;
    if (k < a.size()) {
      std::cout << a[k][x - 1] << '\n';
    } else {
      std::cout << a.back()[x - 1] << '\n';
    }
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}