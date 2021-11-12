#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k, m;
    std::cin >> n >> k >> m;
    --m;
    std::vector<int> a(n), ans(n), cnt(k + 1);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      ans[i] = ++cnt[a[i]];
    }
    for (int i = 0; i < n; ++i) {
      int x = a[i];
      if (cnt[x] % 2) {
        if (ans[i] % 2) {
          ans[i] = m / (2 * n) + (m % (2 * n) >= n + i);
        } else {
          ans[i] = m / (2 * n) + (m % (2 * n) >= i);
        }
      } else {
        if (ans[i] % 2) {
          ans[i] = 0;
        } else {
          ans[i] = m / n + (m % n >= i);
        }
      }
    }
    for (int i = 0; i < n; ++i) std::cout << ans[i] << " \n"[i == n - 1];
  }
  return 0;
}