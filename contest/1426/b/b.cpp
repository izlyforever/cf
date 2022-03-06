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
    bool flag = false;
    for (int i = 0; i < n; ++i) {
      int a, b, c, d;
      std::cin >> a >> b >> c >> d;
      if (b == c) flag = true;
    }
    if (flag && (m % 2 == 0)) print("YES");
    else print("NO");
  }
  return 0;
}
