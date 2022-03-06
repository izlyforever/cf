#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      m -= x;
    }
    print(m == 0 ? "YES" : "NO");
  }
  return 0;
}
