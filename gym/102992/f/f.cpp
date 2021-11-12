#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  std::cout.precision(15);
  while (cas--) {
    LL n, m;
    double p, q;
    std::cin >> n >> m >> p;
    q = 1 - p * 1e-4;
    auto f = [&](int x) -> double {
      return (n * x + m) / (1 - pow(q, x));
    };
    int l = 0, r = 1e9;
    while (r > l) {
      int m = (r - l) / 3;
      int lm = l + m, rm = r - m;
      if (f(lm) < f(rm)) r = rm - 1;
      else l = lm + 1;
    }
    std::cout << std::fixed << f(l) << "\n";
  }
  return 0;
}