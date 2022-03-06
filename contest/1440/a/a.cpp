#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, c[2] , h;
    std::string s;
    std::cin >> n >> c[0] >> c[1] >> h >> s;
    c[0] = std::min(c[0], c[1] + h);
    c[1] = std::min(c[1], c[0] + h);
    int r = 0;
    for (auto& x : s) r += c[x - '0'];
    std::cout << r << std::endl;
  }
  return 0;
}
