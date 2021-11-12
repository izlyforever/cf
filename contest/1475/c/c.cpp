#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int na, nb, k;
    std::cin >> na >> nb >> k;
    std::vector<int> a(na), b(nb);
    for (int i = 0, x; i < k; ++i) {
      std::cin >> x;
      ++a[--x];
    }
    for (int i = 0, x; i < k; ++i) {
      std::cin >> x;
      ++b[--x];
    }
    LL r = LL(k - 1) * k;
    for (auto x : a) r -= LL(x - 1) * x;
    for (auto x : b) r -= LL(x - 1) * x;
    std::cout << r / 2 << "\n";
  }
  return 0;
}