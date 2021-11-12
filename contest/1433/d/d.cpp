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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    auto [mi, mx] = std::minmax_element(a.begin(), a.end());
    if (*mi == *mx) print("NO");
    else {
      print("YES");
      int p1 = mi - a.begin() + 1;
      int p2 = mx - a.begin() + 1;
      for (auto it = a.begin(); it != a.end(); ++it) if (it != mi) {
        if (*it != *mi) std::cout << p1 << " " << it - a.begin() + 1 << std::endl;
        else std::cout << p2 << " " << it - a.begin() + 1 << std::endl;
      }
    }
  }
  return 0;
}