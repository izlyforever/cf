#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 每次可选择 n 减一 或 m 加一，使得 m 是 n 的倍数的最小次数
int solve(int n, int m) {
  if (n > m) return n - m;
  int ans = n - 1;
  // 让 n 变成 i，那么结果就是 n - i + (m % i ? i - m % i : 0) <= n - m % i
  // 注意到 m % i = m - m / i * i 因此可以用数论分块技术加速
  for (int i = 1; i <= n; i = m / (m / i) + 1) {
    ans = std::min(ans, n - m % i);
  }
  // 再特判一下 m % i == 0 的情况
  for (int i = 1; i <= n && i * i <= m; ++i) if (m % i == 0) {
    ans = std::min(ans, n - i);
    if (m / i <= n) ans = std::min(ans, n - m / i);
  }
  return ans;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::cout << solve(n, m) << '\n';
  }
  return 0;
}