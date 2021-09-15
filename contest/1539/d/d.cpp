#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<LL, LL>> a(n);
  for (auto& [x, y] : a) std::cin >> y >> x;
  std::sort(a.begin(), a.end());
  LL cur = 0, ans = 0;
  int i = 0;
  while (i < (int)a.size()) {
    if (cur < a[i].first) {
      LL tmp = a[i].first - cur;
      if (a.back().second <= tmp) {
        cur += a.back().second;
        ans += 2 * a.back().second;
        a.pop_back();
      } else {
        a.back().second -= tmp;
        cur += tmp;
        ans += 2 * tmp;
      }
    } else {
      cur += a[i].second;
      ans += a[i].second;
      ++i;
    }
  }
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}