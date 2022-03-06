#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), l(n), r(n), dp(n);
  for (int i = 0; i < n; ++i) std::cin >> l[i] >> r[i] >> a[i];
  for (int i = n - 1; i >= 0; --i) {
    int need = a[i];
    if (i < n - 1 && r[i] == l[i + 1]) need += dp[i + 1];
    if (LL(r[i] - l[i] + 1) * k < need) {
      print(-1);
      return 0;
    }
    dp[i] = std::max(0LL, need - LL(r[i] - l[i]) * k);
  }
  int cur = k;
  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i];
    if (cur < dp[i]) {
      ans += cur;
      cur = k;
    }
    cur = ((cur - a[i]) % k + k) % k;
  }
  print(ans);
  return 0;
}
