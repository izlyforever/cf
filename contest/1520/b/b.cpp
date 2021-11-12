#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 10;
int dp[N][N];
void init() {
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      dp[i][j] = dp[i - 1][j] * 10 + j;
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  init();
  while (cas--) {
    int n;
    std::cin >> n;
    int r = 0;
    for (int i = 1; i <= 9; ++i) {
      for (int j = 1; j <= 9; ++j) {
        if (dp[i][j] <= n) ++r;
      }
    }
    std::cout << r << '\n';
  }
  return 0;
}