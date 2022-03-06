#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> tag(n), s(n);
    for (auto& x : tag) std::cin >> x;
    for (auto& x : s) std::cin >> x;
    std::vector<LL> dp(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (tag[i] == tag[j]) continue;
        int p = abs(s[i] - s[j]);
        LL dpi = dp[i];
        dp[i] = std::max(dp[i], dp[j] + p);
        dp[j] = std::max(dp[j], dpi + p);
      }
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
