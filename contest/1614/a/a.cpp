#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, l, r, k;
  std::cin >> n >> l >> r >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n && a[i] <= k && a[i] <= r; ++i) if (a[i] >= l) {
    ++ans;
    k -= a[i];
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
