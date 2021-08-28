#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), l(n + 1), r(n + 1), cnt(n + 1), dp(n + 2);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    r[a[i]] = i;
  }
  for (int i = n; i > 0; --i) l[a[i]] = i;
  // dp[i] 表示 [i, n] 中能保存下来最多的数
  for (int i = n; i > 0; --i) {
    ++cnt[a[i]];
    if (l[a[i]] == i) {
      dp[i] = std::max(dp[i + 1], cnt[a[i]] + dp[r[a[i]] + 1]);
    } else {
      dp[i] = std::max(dp[i + 1], cnt[a[i]]);
    }
  }
  std::cout << n - dp[1] << "\n";
  return 0;
}