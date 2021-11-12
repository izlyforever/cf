#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) {
    std::cin >> x;
    x &= 1;
  }
  int ans = n;
  for (int t = 0; t < 2; ++t) {
    int cur = 0;
    for (int op = 0; op < 2; ++op) {
      for (int i = op; i < n; i += 2) {
        if ((a[i] == op) ^ t) ++cur;
      }
    }
    ans = std::min(ans, cur);
  }
  std::cout << ans << '\n';
  return 0;
}