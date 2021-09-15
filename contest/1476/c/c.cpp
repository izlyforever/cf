#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    for (auto& x : c) std::cin >> x;
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    for (int i = 0; i < n; ++i) if (a[i] > b[i]) std::swap(a[i], b[i]);
    LL r = 0, now = b[1] - a[1] + 1;
    for (int i = 2; i < n; ++i) {
      r = std::max(r, now + c[i - 1]);
      if (a[i] == b[i]) {
        now = 1;
      } else {
        now = std::max(now + a[i] + c[i - 1] - b[i] + 1, LL(b[i] - a[i] + 1));
      }
    }
    r = std::max(r, now + c.back());
    std::cout << r << "\n";
  }
  return 0;
}