#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

const int N = 2e5 + 2;
LL dp[N][3][2][2];

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::memset(dp, -0x3f, sizeof(dp));
  auto upmax = [](LL &a, LL b) {
    if (a < b) a = b;
  };
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  if (n == 1) {
    print(a[0]);
    return 0;
  }
  dp[0][1][0][0] = a[0];
  dp[0][2][0][1] = -a[0];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int p = 0; p < 2; ++p) {
          for (int b = 0; b < 2; ++b) {
            int digit = (j + 1 + b) % 3;
            upmax(dp[i][digit][k | (p == b)][b], dp[i - 1][j][k][p] + (b == 0 ? a[i]: -a[i]));
          }
        }
      }
    }
  }
  print(std::max(dp[n - 1][1][1][0], dp[n - 1][1][1][1]));
  return 0;
}