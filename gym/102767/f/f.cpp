#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::pair<int, int> solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n + 1);
  a[0] = 1;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    (a[i] *= a[i - 1]) %= x;
  }
  for (int i = x - 1; i > 0; --i) {
    int len = INT_MAX;
    std::map<int, int> mp;
    for (int j = n; j > 0; --j) {
      mp[a[j]] = j;
      if (mp[a[j - 1] * i % x]) {
        len = std::min(len, mp[a[j - 1] * i % x] - j + 1);
      }
    }
    if (len != INT_MAX) return {i, len};
  }
  return {0, 0};
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    auto [mx, len] = solve();
    std::cout << mx << " " << len << std::endl;
  }
  return 0;
}
