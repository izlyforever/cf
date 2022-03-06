#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  LL m;
  int n;
  std::cin >> m >> n;
  std::vector<LL> pos(n), dist(n);
  for (auto& x : pos) std::cin >> x;
  for (int i = 1; i < n; ++i) dist[i] = pos[i] - pos[i - 1];
  dist[0] = pos[0] + m - pos[n - 1];
  std::rotate(dist.begin(), std::min_element(dist.begin(), dist.end()), dist.end());
  auto check = [dist, n](LL x) -> bool {
    LL last = 0;
    for (int i = 0; i < n; ++i) {
      last = x + last - dist[i];
      if (last < 0) return false;
      last = std::min(last, x - 1);
    }
    return true;
  };
  LL l = (m + n - 1) / n, r = m;
  while (l <= r) {
    auto mid = (l + r) / 2;
    if (check(mid)) r = mid - 1;
    else l = mid + 1;
  }
  std::cout << l << '\n';
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
