#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    if (n <= k) {
      std::cout << k - n << std::endl;
    } else {
      std::cout << ((n - k) & 1) << std::endl;
    }
  }
  return 0;
}