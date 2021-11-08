#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
const int M = 1e9 + 7;

int powMod(int x, int n, int p) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % p;
    n >>= 1;   x = 1LL * x * x % p;
  }
  return r;
}

// 根据情况换成 bool
void solve() {
  int k;
  std::cin >> k;
  std::cout << 6LL * powMod(16, powMod(2, k - 1, M - 1) - 1, M) % M << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}