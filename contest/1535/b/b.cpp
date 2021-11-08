#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a;
    int ans = 0, num = n;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      if (x & 1) {
        a.emplace_back(x);
      } else {
        ans += --num;
      }
    }
    for (int i = a.size() - 1; i > 0; --i) {
      for (int j = 0; j < i; ++j) {
        if (std::gcd(a[i], a[j]) > 1) ++ans;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}