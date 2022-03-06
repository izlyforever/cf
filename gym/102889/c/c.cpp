#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  for (int i = 1; i <= n; ++i) std::cout << i << " \n"[i == n];
  for (int i = 1; i <= n; ++i) std::cout << 1 << " \n"[i == n];
  return 0;
}
