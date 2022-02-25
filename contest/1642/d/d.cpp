#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::deque<int> Q;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    Q.push_back(x);
    ++mp[x];
  }
  for (auto &[_, x] : mp) {
    if (x & 1) {
      std::cout << -1 << '\n';
      return;
    }
  }
  std::vector<std::pair<int, int>> op;
  std::vector<int> ans{0};
  int cur = 0;
  while (!Q.empty()) {
    int x = Q.front();
    int tmp = 1;
    while (Q[tmp] != x) ++tmp;
    cur += tmp;
    for (int i = 1; i < tmp; ++i) {
      op.emplace_back(cur + i, Q[i]);
    }
    cur += tmp;
    ans.emplace_back(cur);
    std::queue<int> S;
    Q.pop_front();
    for (int i = 0; i < tmp - 1; ++i) {
      S.push(Q.front());
      Q.pop_front();
    }
    Q.pop_front();
    while (!S.empty()) {
      Q.push_front(S.front());
      S.pop();
    }
  }
  std::cout << op.size() << '\n';
  for (auto [x, y] : op) std::cout << x << ' ' << y << '\n';
  std::cout << ans.size() - 1 << '\n';
  for (int i = 1, m = (int)ans.size(); i < m; ++i) {
    std::cout << ans[i] - ans[i - 1] << '\n';
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
