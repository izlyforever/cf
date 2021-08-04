#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int x1, y1, z1;
  std::cin >> x1 >> y1 >> z1;
  int x2, y2, z2;
  std::cin >> x2 >> y2 >> z2;
  std::cout << y1 * z2 - y2 * z1 << ' ' << x2 * z1 - x1 * z2 << ' ' << x1 * y2 - x2 * y1 << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}