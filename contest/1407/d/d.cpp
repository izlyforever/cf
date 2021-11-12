#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> h(n), dp(n);
  for (auto& x : h) std::cin >> x;
  std::stack<int> low, high;
  for (int i = 0; i < n; ++i) {
    dp[i] = (i == 0 ? 0 : dp[i - 1] + 1);
    while (!low.empty() && h[i] > h[low.top()]) {
      dp[i] = std::min(dp[i], dp[low.top()] + 1);
      low.pop();
    }
    if (!low.empty()) {
      dp[i] = std::min(dp[i], dp[low.top()] + 1);
      if (h[i] == h[low.top()]) low.pop();
    }
    low.push(i);

    while (!high.empty() && h[i] < h[high.top()]) {
      dp[i] = std::min(dp[i], dp[high.top()] + 1);
      high.pop();
    }
    if (!high.empty()) {
      dp[i] = std::min(dp[i], dp[high.top()] + 1);
      if (h[i] == h[high.top()]) high.pop();
    }
    high.push(i);
  }
  std::cout << dp[n - 1] << std::endl;
  return 0;
}