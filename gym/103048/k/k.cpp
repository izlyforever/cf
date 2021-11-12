#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int l, k;
  std::cin >> l >> k;
  std::cout << (l == 2 && k < 4 ? "Yes" : "No") << '\n';
  return 0;
}