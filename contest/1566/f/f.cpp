#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
const LL INF = 1e18;

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
      dp[i].emplace_back(prefix[i - 1].back());
      int k = 1;
      while (j < m && b[j].second < a[i + 1]) {
        LL cur = b[j].first - a[i];
        while (k < dp[i - 1].size() && a[i] - b[lj - k].second <= cur) ++k;
        dp[i].emplace_back(std::min(prefix[i - 1][dp[i - 1].size() - k] + 2 * cur, suffix[i - 1][dp[i - 1].size() - k] + cur));
        ++j;
      }
    }
    if (i < n) {
      int sz = j - lj;
      prefix[i].resize(sz + 1);
      suffix[i].resize(sz + 1);
      LL tmpL = INT64_MAX, tmpR = INT64_MAX;
      for (int k = 0; k <= sz; ++k) {
        tmpL = std::min(tmpL, dp[i][k] + (k == sz ? 0 : a[i + 1] - b[lj + k].second));
        prefix[i][k] = tmpL;
      }
      // 注意这里有一个偏移，导致上面 dp 计算时没有 + 1
      for (int k = sz; k >= 0; --k) {
        tmpR = std::min(tmpR, dp[i][k] + (k == sz ? 0 : 2 * (a[i + 1] - b[lj + k].second)));
        suffix[i][k] = tmpR;
      }
    }
  }
  std::cout << dp[n].back() << '\n';
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