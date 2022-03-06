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
    if (std::is_sorted(a.begin(), a.end())) {
      std::cout << "0\n";
    } else if (a[0] == 1 || a.back() == n) {
      std::cout << "1\n";
    } else if (a[0] == n && a.back() == 1) {
      std::cout << "3\n";
    } else {
      std::cout << "2\n";
    }
  }
  return 0;
}
