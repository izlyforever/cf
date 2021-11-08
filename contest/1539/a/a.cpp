#include <bits/stdc++.h>
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, x, t;
  std::cin >> n >> x >> t;
  int k = t / x;
  if (k >= n) {
    std::cout << 1LL * n * (n - 1) / 2 << '\n';
  } else {
    std::cout << 1LL * k * (k - 1) / 2 + 1LL * k * (n - k) << '\n';
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}