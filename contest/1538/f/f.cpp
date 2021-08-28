#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int f(int n) {
  int ans = 0;
  while (n) {
    ans += n;
    n /= 10;
  }
  return ans;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << f(r) - f(l) << '\n';
  }
  return 0;
}