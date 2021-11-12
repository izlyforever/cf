#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, l, r;
    std::cin >> n >> l >> r;
    std::vector<int> a(n);
    for (int i = 0, x; i < l; ++i) {
      std::cin >> x;
      --a[--x];
    }
    for (int i = 0, x; i < r; ++i) {
      std::cin >> x;
      ++a[--x];
    }
    int s[2]{}, b[2]{};
    for (int i = 0; i < n; ++i) if (a[i] != 0) {
      b[a[i] > 0] += abs(a[i]) / 2 * 2;
      if (a[i] & 1)  ++s[a[i] > 0];
    }
    int ans = 0;
    bool f = s[1] < s[0];
    if (b[f] >= (s[!f] - s[f])) {
      b[f] -= s[!f] - s[f];
      ans += s[!f] + (b[!f] + b[f]) / 2;
    } else {
      s[!f] -= b[f] + s[f];
      ans += b[f] + s[f] + s[!f] + b[!f] / 2;
    }
    std::cout << ans << '\n';
  }
  return 0;
}