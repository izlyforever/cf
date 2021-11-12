#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string a;
    std::cin >> n >> a;
    std::sort(a.begin(), a.end());
    std::cout << a << std::endl;
  }
  return 0;
}