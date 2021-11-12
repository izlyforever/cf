#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int xa, ya, xb, yb;
  std::cin >> xa >> ya >> xb >> yb;
  if (xa > xb) {
    std::swap(xa, xb);
    std::swap(ya, yb);
  }
  xb -= xa;
  yb -= ya;
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    x -= xa; y -= ya;
    std::cout << (x >= 0 && x <= xb && yb * x == y * xb ? "Yes\n" : "No\n");
  }
  return 0;
}