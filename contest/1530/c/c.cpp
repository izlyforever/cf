#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
  for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
  auto f = [&](int m) -> bool {
    int x = (n + m) / 4;
    return m * 100 + a[n] - a[x] >= b[n] - (x >= m ? b[x - m] : 0);
  };
  int l = 0, r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    if (f(m)) r = m - 1;
    else l = m + 1;
  }
  std::cout << l << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}