#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::reverse(a.begin(), a.end());
  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i];
    a[i] = i - a[i];
  }
  std::sort(a.begin(), a.end());
  for (int i = 0; i < k; ++i) {
    ans += a[i];
  }
  ans -= 1LL * (k - 1) * k / 2;
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
