#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
const LL INF = 1e18;

// 根据情况换成 bool
void solve() {
  int n, m;
  std::cin >> n >> m;
  // 在最左边和最右边加一个点取保边界问题
  std::vector<LL> a(n + 2);
  a[0] = -INF;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  a[n + 1] = INF;
  std::sort(a.begin(), a.end());
  std::vector<std::pair<LL, LL>> b(m);
  for (auto& [x, y] : b) {
    std::cin >> x >> y;
    y = -y;
  }
  std::sort(b.begin(), b.end(), std::greater<>());
  for (auto& [_, y] : b) y = -y;
  std::vector<std::pair<LL, LL>> c;
  c.emplace_back(b[0].first, b[0].second);
  for (int i = 1; i < m; ++i) {
    if (b[i].second < c.back().second) {
      c.emplace_back(b[i]);
    }
  }
  b.clear();
  for (auto& [x, y] : c) {
    auto it = std::lower_bound(a.begin(), a.end(), x);
    if (it == a.end() || *it > y) {
      b.emplace_back(x, y);
    }
  }
  std::reverse(b.begin(), b.end());
  m = b.size();
  // 预处理完成
  std::vector<std::vector<LL>> dp(n + 1), prefix(n), suffix(n);
  for (int i = 0, j = 0, lj = 0; i <= n; ++i, lj = j) {
    if (i == 0) {
      dp[i].emplace_back(0);
      while (j < m && b[j].second < a[i + 1]) {
        dp[i].emplace_back(b[j].first - a[i]);
        ++j;
      }
    } else {
      int k = dp[i - 1].size() - 2, t = lj - dp[i - 1].size();
      dp[i].emplace_back(prefix[i - 1].back());
      while (j < m && b[j].second < a[i + 1]) {
        LL cur = b[j].first - a[i];
        while (k >= 0 && a[i] - b[t + k + 1].second > cur) --k;
        dp[i].emplace_back(std::min(prefix[i - 1][k], suffix[i - 1][k + 1]));
      }
    }
    if (i < n) {
      int sz = dp[i].size();
      prefix[i].resize(sz);
      suffix[i].resize(sz);
      LL tmpL = INT64_MAX, tmpR = INT64_MAX;
      for (int k = 0; k < sz; ++k) {
        tmpL = std::min(tmpL, dp[i][k] + (k + 1 == sz ? 0 : a[i + 1] - b[lj + k + 1].second));
        prefix[i][k] = tmpL;
      }
      for (int k = sz - 1; k >= 0; --k) {
        tmpR = std::min(tmpR, dp[i][k] + (k + 1 == sz ? 0 : 2 * (a[i + 1] - b[lj + k + 1].second)));
        suffix[i][k] = tmpR;
      }
    }
  }
  std::cout << dp[n].back() << '\n';
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