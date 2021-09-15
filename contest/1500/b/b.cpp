#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// ax + by = gcd(a,b)
std::tuple<LL, LL, LL> exGcd(LL a, LL b) {
  if (b == 0) return {a, 1, 0};
  auto [d, y, x] = exGcd(b, a % b);
  return {d, x, y - a / b * x};
}

const int N = 1e6 + 2;
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  LL k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n), b(m);
  for (auto& x : a) std::cin >> x;
  for (auto& x : b) std::cin >> x;
  std::vector<int> pa(N, -1), pb(N, -1);
  for (int i = 0; i < n; ++i) pa[a[i]] = i;
  for (int i = 0; i < m; ++i) pb[b[i]] = i;
  auto [d, tn, tm] = exGcd(n, m);
  LL nm = LL(n) * m, mod = nm / d;
  std::vector<LL> c;
  for (int i = 0; i < N; ++i) if (pa[i] != -1 && pb[i] != -1 && (pa[i] - pb[i]) % d == 0) {
    LL mi = (pa[i] + (pb[i] - pa[i]) / d * tn % m * n) % mod;
    if (mi < 0) mi += mod;
    c.emplace_back(mi);
  }
  auto f = [&](LL x) {
    LL r = x, tx = x % mod;
    for (auto val : c) if (val < tx) --r;
    return r - x / mod * c.size();
  };
  LL l = k, r = k * std::max(n, m);
  while (l <= r) {
    LL m = (l + r) / 2;
    if (f(m) >= k) r = m - 1;
    else l = m + 1;
  }
  std::cout << l << '\n';
  return 0;
}