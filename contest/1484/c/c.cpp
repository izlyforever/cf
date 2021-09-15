#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> sz(m), p(m), ans(m), cnt(n + 1);
  std::vector<std::vector<int>> k(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> sz[i];
    k[i].resize(sz[i]);
    for (auto& x : k[i]) {
      std::cin >> x;
      ++cnt[x];
    }
  }
  int m2 = (m + 1) / 2;
  int x = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
  if (cnt[x] > m2) {
    int c = 0;
    for (int i = 0; i < m; ++i) if (sz[i] == 1) {
      ans[i] = k[i][0];
      if (ans[i] == x) ++c;
    }
    if (c > m2) {
      std::cout << "NO\n";
      return;
    }
    for (int i = 0; i < m; ++i) if (ans[i] == 0) {
      if (std::find(k[i].begin(), k[i].end(), x) == k[i].end()) {
        ans[i] = k[i][0];
      } else if (c == m2) {
        ans[i] = k[i].back() == x ? k[i][0] : k[i].back();
      } else {
        ans[i] = x;
        ++c;
      }
    }
  } else {
    for (int i = 0; i < m; ++i) ans[i] = k[i].back();
  }
  std::cout << "YES\n";
  for (auto x : ans) std::cout << x << ' ';
  std::cout << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}