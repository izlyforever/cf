#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const LL INF = 1e13;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  for (int i = 1; i < n; ++i) if (a[i] > 0 && a[i - 1] > 0) return false;
  if (std::count_if(a.begin(), a.end(), [&](int x) {
      return x > 0;
    }) <= 1) {
      return true;
  }
  auto f = [&](LL mx) -> LL {
    for (auto &x : a) if (x > mx) x = -INF;
    LL sm = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      sm += a[i];
      ans = std::max(ans, sm);
      sm = std::max(0LL, sm);
    }
    return ans;
  };
  LL now = 1e9;
  while (now > 0) {
    LL cur = f(now);
    if (cur > now) return false;
    now = cur - 1;
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
