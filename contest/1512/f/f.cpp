#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n), b(n - 1);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    b.push_back(0);
    LL ans = INT64_MAX, cur = 0, s = 0;
    for (int i = 0; i < n; ++i) {
      ans = std::min(ans, cur + std::max(0LL, c - s + a[i] - 1) / a[i]);
      LL newDay = std::max(0LL, b[i] - s + a[i] - 1) / a[i];
      cur += newDay + 1;
      s += a[i] * newDay - b[i];
    }
    std::cout << ans << '\n';
  }
  return 0;
}
