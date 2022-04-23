#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  auto f = [&](int x) {
    int mn = std::min(abs(a[0] - x), abs(a.back() - x));
    for (int i = 0; i < n; ++i) {
      mn = std::min(mn, 2 * abs(a[i] - x));
    }
    return mn;
  };
  LL ans = f(1);
  int mx = *std::max_element(a.begin(), a.end());
  if (k > mx) {
    ans += f(k);
  }
  for (int i = 1; i < n; ++i) {
    ans += abs(a[i] - a[i - 1]);
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
