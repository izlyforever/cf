#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353;
const LL inv2 = (M + 1) / 2;
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
  int n;
  std::cin >> n;
  std::vector<LL> a(n + 1);
  a[1] = 1;
  LL odd = 1, even = 1;
  auto add = [](LL& x, LL y) {
    (x += y) >= M && (x -= M);
  };
  for (int i = 2; i <= n; ++i) {
    if (i % 2 == 0) {
      a[i] = odd;
      add(even, a[i]);
    } else {
      a[i] = even;
      add(odd, a[i]);
    }
  }
  std::cout << a[n] * powMod(inv2, n) % M << std::endl;
  return 0;
}