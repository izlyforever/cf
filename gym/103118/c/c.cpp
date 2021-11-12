#include <bits/stdc++.h>
using LL = long long;
const int N = 1e5 + 2;
int p[N];
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    LL k;
    std::cin >> k;
    int n = 0, rt = 0;
    while (k > 2) {
      --k;
      while (k % 2 == 0) {
        p[++n] = rt;
        k /= 2;
      }
      if (k > 2) {
        p[++n] = rt;
        rt = n;
      }
    }
    std::cout << n + 1 << '\n';
    for (int i = 1; i <= n; ++i) {
      std::cout << p[i] + 1 << ' ' << i + 1 << '\n';
    }
  }
  return 0;
}