#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::vector<int> dp(n + 1, 1e9);
    std::sort(a.begin(), a.end());
    dp[0] = 0;
    for (int i = 1; i < 2 * n; ++i) {
      for (int j = n; j > 0; --j) dp[j] = std::min(dp[j], dp[j - 1] + abs(a[j - 1] - i));
    }
    print(dp[n]);
  }
  return 0;
}