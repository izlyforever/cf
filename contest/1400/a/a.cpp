#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string a;
    std::cin >> n >> a;
    for (int i = 0; i < n; ++i) std::cout << a[i << 1];
    std::cout << std::endl;
  }
  return 0;
}