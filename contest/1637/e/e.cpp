#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++mp[x];
  }
  std::set<std::pair<int, int>> b;
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    b.emplace(x, y);
    b.emplace(y, x);
  }

  auto getAns1 = [&](const std::vector<int> x) {
    int ans = 0;
    for (int i = x.size() - 1; i >= 0; --i) {
      for (int j = i - 1, t = ans - x[i]; j >= 0 && x[j] > t; --j) {
        if (!b.count({x[i], x[j]})) {
          ans = x[i] + x[j];
          break;
        }
      }
    }
    return ans;
  };
  auto getAns2 = [&](const std::vector<int> x, const std::vector<int> y) {
    int ans = 0;
    for (int i = x.size() - 1; i >= 0; --i) {
      for (int j = y.size() - 1, t = ans - x[i]; j >= 0 && y[j] > t; --j) {
        if (!b.count({x[i], y[j]})) {
          ans = x[i] + y[j];
          break;
        }
      }
    }
    return ans;
  };

  std::vector<std::vector<int>> lst(n + 1);
  for (auto [x, y] : mp) {
    lst[y].emplace_back(x);
  }
  std::vector<int> noEmpty;
  for (int i = 1; i <= n; ++i) {
    if (!lst[i].empty()) {
      noEmpty.emplace_back(i);
      assert(std::is_sorted(lst[i].begin(), lst[i].end()));
    }
  }
  LL ans = 0;
  for (int i = noEmpty.size() - 1; i >= 0; --i) {
    int ni = noEmpty[i];
    ans = std::max(ans, 2LL * ni * getAns1(lst[ni]));
    for (int j = i - 1; j >= 0; --j) {
      int nj = noEmpty[j];
      ans = std::max(ans, 1LL * (ni + nj) * getAns2(lst[ni], lst[nj]));
    }
  }
  std::cout << ans << '\n';
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