#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  if (is_sorted(a.begin(), a.end())) {
    std::cout << 0 << '\n';
    return;
  }
  if (a[n - 1] < a[n - 2] || a[n - 1] < 0) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << n - 2 << '\n';
  for (int i = 1; i <= n - 2; ++i) {
    std::cout << i << ' ' << n - 1 << ' ' << n << '\n';
  }
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
