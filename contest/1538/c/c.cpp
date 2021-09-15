#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    auto f = [&](int x) {
      return std::upper_bound(a.begin(), a.end(), x) - a.begin();
    };
    LL ans = 0;
    while (!a.empty()) {
      int x = a.back();
      a.pop_back();
      ans += f(r - x) - f(l - 1 - x);
    }
    std::cout << ans << '\n';
  }
  return 0;
}