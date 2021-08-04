#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;

int main() {
  //freopen("in","r",stdin);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cout << 1 << " \n"[i == n - 1];
  }
  return 0;
}