#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int i = 2;
  while (i * i <= n && n % i) ++i;
  i = (n % i == 0 ? n / i : 1);
  std::cout << i << " " << n - i << std::endl;
  return 0;
}