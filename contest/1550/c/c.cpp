#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (auto& x : a) std::cin >> x;
    int ans = 2 * n - 1;
    for (int i = 1; i < n - 1; ++i) {
        if (1LL * (a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0) ++ans;
    }
    for (int i = 2; i < n - 1; ++i) {
        if (1LL * (a[i - 1] - a[i - 2]) * (a[i - 1] - a[i]) > 0 &&
            1LL * (a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0 &&
            1LL * (a[i - 1] - a[i - 2]) * (a[i - 1] - a[i + 1]) > 0 &&
            1LL * (a[i] - a[i - 2]) * (a[i] - a[i + 1]) > 0) ++ans;
    }
    std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
