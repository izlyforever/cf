#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
int solve(int n) {
  int r = 0;
  int now = 0;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    now += x;
    if (now > 0) {
      r += now;
      now = 0;
    }
  }
  return r;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int r = 0;
    int n;
    std::cin >> n;
    r += solve(n);
    int m;
    std::cin >> m;
    r += solve(m);
    std::cout << r << std::endl;
  }
  return 0;
}