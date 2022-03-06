#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<typename T>
T floor(T a, T n) {
  if (n < 0) {
    n = -n;
    a = -a;
  }
  return a < 0 ? (a - n + 1) / n : a / n;
}

LL solve() {
  int n;
  LL k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  LL sm = std::accumulate(a.begin(), a.end(), 0LL);
  if (sm <= k) return 0;
  // x * (i + 1) + sm <= k
  sm -= a[0];
  LL ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    LL now = floor(k - sm, LL(i + 1));
    ans = std::min(ans, i + std::max(0LL, a[0] - now));
    sm -= a[n - 1 - i];
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
