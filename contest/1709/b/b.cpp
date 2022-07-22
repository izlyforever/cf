#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<LL> l(n), r(n);
  {
    LL now = 0;
    for (int i = 1; i < n; ++i) {
      now += std::max(a[i - 1] - a[i], 0);
      l[i] = now;
    }
  }
  {
    LL now = 0;
    for (int i = n - 1; i > 0; --i) {
      now += std::max(a[i] - a[i - 1], 0);
      r[i - 1] = now;
    }
  }
  auto get = [&](int L, int R) {
    return L > R ? r[R] - r[L] : l[R] - l[L];
  };
  for (int i = 0; i < m; ++i) {
    int L, R;
    std::cin >> L >> R;
    std::cout << get(--L, --R) << '\n';
  }
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
