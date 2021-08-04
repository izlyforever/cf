#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, p, q, m, b, c, t;
  std::cin >> n >> p >> q >> m >> b >> c >> t;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i].first;
    a[i].second = i + 1;
  }
  for (int i = m; i < n; ++i) {
    a[i].first = (LL(b) * a[i - 1].first + c) % t + 1;
    a[i].second = i + 1;
  }
  std::sort(a.begin(), a.end());
  for (int i = 0; i + 1 < n; ++i) if (LL(a[i + 1].first) * p <= LL(a[i].first) * q) {
    std::cout << std::min(a[i].second, a[i + 1].second) << " " << std::max(a[i].second, a[i + 1].second) << std::endl;
    return 0;
  }
  std::cout << -1 << std::endl;
  return 0;
}