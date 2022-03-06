#include <bits/stdc++.h>
using LL = long long;

int floor(int a, int n) { // n > 0
  return a < 0 ? (a - n + 1) / n : a / n;
}
int ceil(int a, int n) { // n > 0
  return a < 0 ? a / n : (a + n - 1) / n;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (auto& x : a) std::cin >> x;
  for (auto& x : b) std::cin >> x;
  std::sort(a.begin(), a.end());
  auto solve = [&](int x, int y) -> int { // y <= a <= x
    auto itx = std::upper_bound(a.begin(), a.end(), x);// <= x
    auto ity = std::lower_bound(a.begin(), a.end(), y);// < y
    return itx - ity;
  };
  int l, r;
  std::cin >> l >> r;
  LL ans = 0;
  for (auto x : b) {
    if (x == 0) {
      if (r >= 0 && l <= 0) ans += n;
    } else if (x > 0) {
      ans += solve(floor(r, x), ceil(l, x));
    } else {
      ans += solve(floor(-l, -x), ceil(-r, -x));
    }
  }
  std::cout << ans << '\n';
  return 0;
}
