#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int solve() {
  int a, b, c;
  std::cin >> a >> b >> c;
  // if a, b, c can be 0
  
  if (a == 0) {
    if (c & 1) return b == 0 ? 3 : 1;
    return c > 0 ? 0 : (b & 1);
  }
  if (c & 1) {
    if (b == 0) return a >= 3 ? (a - 3) & 1 : 3 - a;
    return (a - 1) & 1;
  }
  return a & 1;

  // if abc not equal 0
  if (c & 1) return (a - 1) & 1;
  return a & 1;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}