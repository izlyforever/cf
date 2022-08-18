#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<int> dp(n, 1);
  for (int i = 1; i < n; ++i) {
    for (int j = std::max(0, i - 400); j < i; ++j) {
      if ((a[j] ^ i) < (a[i] ^ j)) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }
  int ans = *std::max_element(dp.begin(), dp.end());
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
