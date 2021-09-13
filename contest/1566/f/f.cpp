#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  std::vector<std::pair<int, int>> b(m);
  for (auto &[x, y] : b) {
    std::cin >> x >> y;
    y = -y;
  }
  std::sort(b.begin(), b.end(), std::greater<>());
  for (auto &[_, y] : b) y = -y;
  std::vector<std::pair<int, int>> c;
  c.emplace_back(b[0].first, b[0].second);
  for (int i = 1; i < m; ++i) {
    if (b[i].second < c.back().second) {
      c.emplace_back(b[i]);
    }
  }
  b.clear();
  for (auto &[x, y] : c) {
    auto it = std::lower_bound(a.begin(), a.end(), x);
    if (it == a.end() || *it > y) {
      b.emplace_back(x, y);
    }
  }
  m = b.size();
  // 预处理完成

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