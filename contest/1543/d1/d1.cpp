#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, k;
  std::cin >> n >> k;
  auto f = [k](int x, int y) {
    int z = 0, c = 1;
    while (x || y) {
      z += (x % k + y % k) % k * c;
      x /= k;
      y /= k;
      c *= k;
    }
    return z;
  };
  for (int i = 0, cur = 0; i < n; ++i) {
    int tmp = f(i, cur);
    std::cout << tmp << std::endl;
    cur = f(cur, tmp);
    int x;
    std::cin >> x;
    if (x == 1) return;
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}