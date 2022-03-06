#include <bits/stdc++.h>
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
