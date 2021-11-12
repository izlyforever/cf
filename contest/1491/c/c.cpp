#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<LL> a(n), b(n + 1);
    for (auto& x : a) std::cin >> x;
    LL r = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 2; j <= a[i] && i + j < n; ++j) ++b[i + j];
      if (b[i] >= a[i]) {
        b[i + 1] += b[i] - a[i] + 1;
      } else {
        r += a[i] - b[i] - 1;
      }
    }
    std::cout << r << "\n";
  }
  return 0;
}