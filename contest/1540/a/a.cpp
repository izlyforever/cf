#include <bits/stdc++.h>
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  LL ans = a.back(), cur = 0;
  for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1];
  for (int i = 1; i < n; ++i) {
    cur += 1LL * a[i] * i;
    ans -= cur;
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
