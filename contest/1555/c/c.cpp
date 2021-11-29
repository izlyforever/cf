#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto& x : a) std::cin >> x;
  for (auto& x : b) std::cin >> x;
  int ans = INT_MAX;
  for (int i = 1; i < n; ++i) b[i] += b[i - 1];
  for (int i = n - 1; i > 0; --i) a[i - 1] += a[i];
  for (int i = 0; i < n; ++i) ans = std::min(ans, std::max((i == 0 ? 0 : b[i - 1]), (i == n - 1 ? 0 : a[i + 1])));
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