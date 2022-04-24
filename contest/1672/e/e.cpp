#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int l = 1, r = 2001 * n;
  std::vector<int> query_(r + 1, -1);
  int cnt = 0;
  auto query = [&](int x) {
    if (x <= 0) return 0;
    if (query_[x] != -1) return query_[x];
    ++cnt;
    std::cout << "? " << x << std::endl;
    int ans;
    std::cin >> ans;
    return query_[x] = ans;
  };
  while (l < r) {
    int m = (l + r) / 2;
    if (query(m) == 1) r = m;
    else l = m + 1;
  }
  int ans = r;
  for (int i = 1; i <= n; ++i) {
    int x = query(r / i);
    if (x == 0) break;
    ans = std::min(ans, r / i * x);
  }
  cerr(cnt);
  std::cout << "! " << ans << '\n';
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
