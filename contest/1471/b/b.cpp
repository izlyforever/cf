#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, x;
    std::cin >> n >> x;
    auto f = [&](int t) {
      int r = 0;
      while (t % x == 0) {
        ++r;
        t /= x;
      }
      return r;
    };
    std::vector<int> a(n), c(n);
    for (auto& x : a) std::cin >> x;
    for (int i = 0; i < n; ++i) c[i] = f(a[i]);
    std::vector<LL> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; ++i) b[i] = b[i - 1] + a[i];
    int it = std::min_element(c.begin(), c.end()) - c.begin();
    std::cout << b.back() * (c[it] + 1) + (it > 0 ? b[it - 1] : 0) << std::endl;
  }
  return 0;
}