#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::set<int> s(a.begin(), a.end());
  int mx = 0, times = 0;
  while (mx <= n) {
    if (!s.count(mx) && times++ == k) break;
    ++mx;
  }
  if (mx == n) {
    std::cout << 0 << '\n';
  } else {
    std::map<int, int> mp;
    for (auto &x : a) if (x >= mx) ++mp[x];
    std::vector<int> cnt(n + 1);
    for (auto &[_, c] : mp) ++cnt[c];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int x = cnt[i];
      while (x) {
        if (k >= i) {
          k -= i;
        } else {
          ++ans;
        }
        --x;
      }
    }
    std::cout << ans << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
