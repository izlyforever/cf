#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];
  auto check = [&](int k) -> bool {
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] >= cur && a[i] >= k - 1 - cur) ++cur;
    }
    return cur >= k;
  };
  int l = 1, r = n;
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