#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), cnt(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    --a[i];
    ++cnt[(i - a[i] + n) % n];
  }
  std::vector<int> ans;
  for (int k = 0; k < n; ++k) if (cnt[k] >= n - 2 * m) {
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) p[(i - k + n) % n] = a[i];
    int cyc = 0;
    std::vector<int> vis(n);
    for (int i = 0; i < n; ++i) if (!vis[i]) {
      int j = i;
      while (!vis[j]) {
        vis[j] = true;
        j = p[j];
      }
      ++cyc;
    }
    if (n - cyc <= m) ans.emplace_back(k);
  }
  std::cout << ans.size();
  for (auto x : ans) std::cout << ' ' << x;
  std::cout << '\n';
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