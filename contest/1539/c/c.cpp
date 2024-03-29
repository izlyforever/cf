#include <bits/stdc++.h>
using LL = long long;

void solve() {
  int n;
  LL k, x;
  std::cin >> n >> k >> x;
  std::vector<LL> a(n), b;
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] - a[i - 1] > x) {
      ++ans;
      b.emplace_back((a[i] - a[i - 1] - 1) / x);
    }
  }
  std::sort(b.begin(), b.end());
  for (int i = 0, nb = b.size(); i < nb; ++i) {
    if (k >= b[i]) {
      --ans;
      k -= b[i];
    }
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
