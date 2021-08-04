#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl;
using LL = long long;

LL f(LL n) {
  if (n <= 1) return n;
  if (n % 2 == 1) return n - f(n - 1);
  if (n % 4 == 2) return n - f(n / 2);
  if (n == 4) return 3;
  return 1 + f(n - 2);
}

int main() {
  //freopen("in","r",stdin);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int cas;
  std::cin >> cas;
  while (cas--) {
    LL n;
    std::cin >> n;
    print(f(n));
  }
  return 0;
}