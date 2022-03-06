#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  freopen("equal.in","r",stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int d = a ^ b ^ c;
    std::cout << (d == a || d == b || d == c ? "YES" : "NO") << std::endl;
  }
  return 0;
}
