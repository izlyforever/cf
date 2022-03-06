#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    a[i] = {x, i + 1};
  }
  std::sort(a.begin(), a.end(), std::greater<>());
  LL time = 0;
  std::vector<int> ans(n + 1);
  for (int i = 0, x = 1; i < n; ++i) {
    time += 1LL * a[i].first * x;
    if (i & 1) {
      ans[a[i].second] = -x;
      ++x;
    } else {
      ans[a[i].second] = x;
    }
  }
  std::cout << time * 2 << '\n';
  for (int i = 0; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
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
