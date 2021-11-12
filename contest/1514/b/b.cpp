#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 1e9 + 7;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    LL r = 1;
    for (int i = 0; i < k; ++i) r = r * n % M;
    std::cout << r << '\n';
  }
  return 0;
}