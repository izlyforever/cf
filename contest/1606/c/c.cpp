#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  ++k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<LL> ten{1};
  for (int i = 1; i <= 10; ++i) ten.emplace_back(ten.back() * 10);
  LL ans = 0;
  for (int i = 1; i < n; ++i) {
    int now = (int)std::min((LL)k, ten[a[i] - a[i - 1]] - 1);
    k -= now;
    ans += now * ten[a[i - 1]];
  }
  ans += k * ten[a.back()];
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
