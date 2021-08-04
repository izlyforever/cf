#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<LL> p(n);
    for (auto &x : p) std::cin >> x;
    LL r = 0, s = p[0];
    for (int i = 1; i < n; ++i) {
      if (s * k < p[i] * 100) {
        r  = std::max(r, (p[i] * 100 + k - 1) / k - s);
      }
      s += p[i];
    }
    std::cout << r << "\n";
  }
  return 0;
}