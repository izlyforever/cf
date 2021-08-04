#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 1e9 + 7;
LL powMod(LL x, LL n) {
  LL r = 1;
  while (n) {
    if (n & 1) r = r * x % M;
    n >>= 1;   x = x * x % M;
  }
  return r;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL n, x;
    std::cin >> n >> x;
    std::cout << (powMod(2, n) + M - 1) * x % M << std::endl;
  }
  return 0;
}