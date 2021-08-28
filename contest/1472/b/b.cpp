#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    int a[3]{};
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      ++a[x];
    }
    if (a[1] % 2 == 1 || (a[2] % 2 == 1 && a[1] == 0)) {
      std::cout << "NO\n";
    } else std::cout << "YES\n";
  }
  return 0;
}