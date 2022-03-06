#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  LL h;
  std::cin >> n >> h;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  auto f = [&](LL k) -> LL {
    LL sum = 0, last = a[0];
    for (int i = 1; i < n; ++i) {
      if (a[i] - a[i - 1] > k) {
        sum += (a[i - 1] + k - last);
        last = a[i];
      }
    }
    return sum + a.back() + k - last;
  };
  LL l = 1, r = h;
  while (l <= r) {
    auto m = (l + r) / 2;
    if (f(m) >= h) r = m - 1;
    else l = m + 1;
  }
  std::cout << l << '\n';
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
