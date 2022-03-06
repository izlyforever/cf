#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int x;
  std::cin >> x;
  int n = x / 1000;
  int mod = x % 1000, r = 1;
  for (int i = n; i > 1; i -= 2) r = r * i % mod;
  std::cout << r << '\n';
  return 0;
}
