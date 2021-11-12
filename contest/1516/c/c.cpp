#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  int sm = std::accumulate(a.begin(), a.end(), 0);
  if (sm & 1) {
    std::cout << "0\n";
    return 0;
  }
  sm /= 2;
  std::vector<int> dp(sm + 1);
  for (auto x : a) {
    for (int j = sm; j >= x; --j) {
      dp[j] = std::max(dp[j], dp[j - x] + x);
    }
  }
  if (dp[sm] == sm) {
    for (auto& x : a) x = __builtin_ctz(x);
    std::cout << "1\n";
    std::cout << 1 + std::distance(a.begin(), std::min_element(a.begin(), a.end())) << '\n';
  } else {
    std::cout << "0\n";
  }
  return 0;
}