#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

LL f(int l, int r) {
  return 1LL * (r - l + 1) * (l + r) / 2;
}

void solve() {
  int k;
  LL x;
  std::cin >> k >> x;
  int ans = 0;
  if (f(1, k) < x) {
    x -= f(1, k);
    ans += k;
    int l = 1, r = k - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (f(k - m, k - 1) < x) l = m + 1;
      else r = m - 1;
    }
    ans += l;
  } else {
    int l = 1, r = k;
    while (l <= r) {
      int m = (l + r) / 2;
      if (f(1, m) < x) l = m + 1;
      else r = m - 1;
    }
    ans += l;
  }
  std::cout << std::min(2 * k - 1, ans) << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
