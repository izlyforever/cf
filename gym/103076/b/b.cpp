#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0, sz; i < n; ++i) {
    std::cin >> sz;
    for (int j = 0, x; j < sz; ++j) {
      std::cin >> x;
      a[i] |= 1 << --x;
    }
  }
  auto check = [&](int x) {
    for (int i = 0; i < n; ++i) {
      if (x & (1 << i)) {
        if ((x & a[i]) == a[i]) return 0;
      } else {
        if ((x & a[i]) != a[i]) return 0;
      }
    }
    return 1;
  };
  int ans = 0;
  for (int i = 0; i < (1 << n); ++i) ans += check(i);
  std::cout << ans << '\n';
  return 0;
}
