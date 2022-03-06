#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  freopen("sticks.in","r",stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::vector<int> a(3);
    int x;
    std::cin >> a[0] >> a[1] >> a[2] >> x;
    std::sort(a.begin(), a.end());
    double r = a[1] * a[2] * 0.5;
    if (a[1] * a[1] + a[2] * a[2] > (a[0] + x) * (a[0] + x)) {
      a[0] += x;
      double p = (a[0] + a[1] + a[2]) / 2.0;
      r = std::sqrt(p * (p - a[0]) * (p - a[1]) * (p - a[2]));
    };
    std::cout.precision(12);
    std::cout << std::fixed << r << std::endl;
  }
  return 0;
}
