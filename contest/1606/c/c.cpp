#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, k;
  std::cin >> n >> k;
  ++k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<LL> ten{1};
  for (int i = 1; i <= 10; ++i) ten.emplace_back(ten.back() * 10);
  LL ans = 0;
  for (int i = 1; i < n; ++i) {
    int now = (int)std::min((LL)k, ten[a[i] - a[i - 1]] - 1);
    k -= now;
    ans += now * ten[a[i - 1]];
  }
  ans += k * ten[a.back()];
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}
