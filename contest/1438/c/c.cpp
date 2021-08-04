#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;

int main() {
  // freopen("in","r",stdin);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0, x; j < m; ++j) {
        std::cin >> x;
        if ((x + i + j) & 1) ++x;
        std::cout << x << " \n"[j == m - 1];
      }
    }
  }
  return 0;
}