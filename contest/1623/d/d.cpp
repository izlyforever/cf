#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int M = 1e9 + 7;
int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

void solve() {
  int dx = 1, dy = 1;
  int n, m, x, y, a, b, p;
  std::cin >> n >> m >> x >> y >> a >> b >> p;
  p = 1LL * p * powMod(100, M - 2) % M;
  int q = (M + 1 - p) % M;

  --x; --y;
  --a; --b;
  auto nextStep = [&]() {
    x += dx;
    y += dy;
    if (x >= n) {
      x = n - 2;
      dx = -dx;
    } else if (x < 0) {
      x = 1;
      dx = -dx;
    }
    if (y >= m) {
      y = m - 2;
      dy = -dy;
    } else if (y < 0) {
      y = 1;
      dy = -dy;
    }
  };

  int cur = 1, ans = 0;
  int nm = 2 * std::lcm(n - 1, m - 1);
  for (int i = 0; i < nm; ++i) {
    if (x == a || y == b) {
      ans = (ans + 1LL * cur * p % M * i) % M;
      cur = 1LL * cur * q % M;
    }
    nextStep();
  }
  ans = (ans + 1LL * cur * nm) % M * powMod(M + 1 - cur, M - 2) % M;
  std::cout << ans << '\n';
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