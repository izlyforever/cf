#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
    std::cout << i << n / i << '\n';
  }
  return 0;
}
