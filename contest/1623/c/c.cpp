#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  auto check = [&](int m) -> bool {
    auto h = a;
    for (int i = n - 1; i >= 2; --i) {
      if (h[i] < m) return false;
      int now = std::min(h[i] - m, a[i]) / 3;
      h[i - 1] += now;
      h[i - 2] += now * 2;
    }
    return h[0] >= m && h[1] >= m;
  };
  int l = 0, r = a.back();
  while (l <= r) {
    int m = (l + r) / 2;
    if (check(m)) l = m + 1;
    else r = m - 1;
  }
  std::cout << r << '\n';
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
