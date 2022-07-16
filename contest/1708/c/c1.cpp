#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  auto check = [&](int m) {
    int qq = q;
    for (int i = m; i < n; ++i) {
      if (a[i] > qq) {
        --qq;
      }
    }
    return qq >= 0;
  };
  int l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) r = m;
    else l = m + 1;
  }
  std::string ans(n, '1');
  for (int i = 0; i < r; ++i) {
    if (a[i] > q) ans[i] = '0';
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
