#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL a[3], p;
    std::cin >> p;
    for (int i = 0; i < 3; ++i) std::cin >> a[i];
    LL r = INT64_MAX;
    for (int i = 0; i < 3; ++i) {
      LL t = p % a[i];
      r = std::min(r, (t == 0 ? 0 : a[i] - t));
    }
    std::cout << r << "\n";
  }
  return 0;
}