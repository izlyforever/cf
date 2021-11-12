#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::priority_queue<std::pair<int, int>> Q;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    if (x > 0) {
      Q.emplace(x, i);
    }
  }
  std::vector<std::pair<int, int>> ans;
  while (Q.size() > 1) {
    auto [x, i] = Q.top();
    Q.pop();
    auto [y, j] = Q.top();
    Q.pop();
    if (--x) {
      Q.emplace(x, i);
    }
    if (--y) {
      Q.emplace(y, j);
    }
    ans.emplace_back(i, j);
  }
  std::cout << ans.size() << '\n';
  for (auto [i, j] : ans) std::cout << i << ' ' << j << '\n';
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