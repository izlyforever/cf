#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<LL> a(n), ans(m);
    for (auto& x : a) std::cin >> x;
    auto check = [&](int i, int j, int k) {
      return a[k] * (j - i) > a[j] * (k - i) - a[i] * (k - j);
    };
    std::vector<int> Q;
    for (int i = 0; i < n; ++i) {
      while (Q.size() > 1 && check(Q[Q.size() - 2], Q[Q.size() - 1], i)) Q.pop_back();
      Q.emplace_back(i);
    }
    std::vector<std::pair<LL, LL>> b(m);
    for (auto& [x, d] : b) std::cin >> x >> d;
    std::vector<int> p(m);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
      return b[i].second < b[j].second;
    });
    for (int i = 0; i < m; ++i) {
      auto [x, d] = b[p[i]];
      while (Q.size() > 1 && (Q[Q.size() - 1] - Q[Q.size() - 2]) * d >= a[Q[Q.size() - 1]] - a[Q[Q.size() - 2]]) {
        Q.pop_back();
      }
      ans[p[i]] = x + Q.back() * d - a[Q.back()];
    }
    for (int i = 0; i < m; ++i) std::cout << ans[i] << '\n';
  }
  return 0;
}