#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 1003;
std::vector<int> f(2 * N);

void init() {
  std::iota(f.begin(), f.end(), -1);
  for (int i = 1; i < N; ++i) {
    // for (int j = i; j > 0 && i + i / j < N; --j) {
    //   f[i + i / j] = std::min(f[i + i / j], f[i] + 1);
    // }
    for (int j = 1, k; j <= i; j = i / k + 1) {
      k = i / j;
      f[i + k] = std::min(f[i + k], f[i] + 1);
    }
  }
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> b(n), c(n);
  for (auto &x : b) {
    std::cin >> x;
    x = f[x];
  }
  for (auto &x : c) std::cin >> x;
  std::vector<int> dp(k + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = k; j >= b[i]; --j) {
      dp[j] = std::max(dp[j], dp[j - b[i]] + c[i]);
    }
  }
  std::cout << dp[k] << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}