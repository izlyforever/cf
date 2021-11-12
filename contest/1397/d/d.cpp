#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int s = 0;
    for (auto& x : a) {
      std::cin >> x;
      s += x;
    }
    int mx = *std::max_element(a.begin(), a.end());
    if (n == 1 || (s & 1 ) || s < 2 * mx) {
      std::cout << "T\n";
    } else std::cout << "HL\n";
  }
  return 0;
}