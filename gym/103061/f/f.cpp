#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<double, double>> a(n);
  const double eps = 1e-6;
  for (auto &[l, r] : a) std::cin >> l >> r, r += eps;
  auto check = [&](double mid) {
    double p = 0;
    for (auto [L, R] : a) if (L < mid) {
      p += (std::min(R, mid) - L) / (R - L);
    }
    return p >= m;
  };
  double l = 0, r = 1e9;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid;
  }
  std::cout.precision(12);
  std::cout << std::fixed << (l + r) / 2 << '\n';
  return 0;
}