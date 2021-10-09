#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<std::tuple<int, int, int>> ans;
  for (int i = 0; i < n; ++i) {
    int it = std::max_element(a.begin(), a.end()) - a.begin();
    if (it != n - i - 1) {
      ans.emplace_back(it + 1, n - i, 1);
    }
    a.erase(a.begin() + it);
  }
  std::cout << ans.size() << '\n';
  for (auto [l, r, d] : ans) std::cout << l << ' ' << r << ' ' << d << '\n';
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