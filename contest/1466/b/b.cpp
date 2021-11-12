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
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int r = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] > a[i - 1]) {
        ++r;
      } else if (a[i] == a[i - 1]) {
        ++r;
        ++a[i];
      } else ++a[i];
    }
    std::cout << r << std::endl;
  }
  return 0;
}