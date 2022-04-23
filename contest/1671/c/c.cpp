#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  LL s;
  std::cin >> n >> s;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];
  LL ans = 0;
  for (int i = 0; i < n && a[i] <= s; ++i) {
    ans += (s - a[i]) / (i + 1) + 1;
  }
  std::cout << ans << '\n';
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
