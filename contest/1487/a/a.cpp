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
    int mx = *std::min_element(a.begin(), a.end());
    int r = 0;
    for (auto x : a) if (x > mx) ++r;
    std::cout << r << std::endl;
  }
  return 0;
}
