#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(k);
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    ++a[--x];
  }
  LL r = 1;
  for (int i = 0; i < k; ++i) {
    r *= (1LL << a[i]) - 1;
  }
  std::cout << r << std::endl;
  return 0;
}