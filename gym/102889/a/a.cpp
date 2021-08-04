#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  double r = 100 * n * pow(1.1, n);
  for (int i = 0; i < n; ++i) r = std::max(r, 100 * (2 * n - i) * pow(1.1, i));
  std::cout.precision(15);
  std::cout << std::fixed << r << std::endl;
  return 0;
}