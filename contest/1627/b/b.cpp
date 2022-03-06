#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  auto dist = [&](int i, int j) {
    return std::max({i + j, i + m - 1 - j, n - 1 - i + j, n - 1 - i + m - 1 - j});
  };
  int nm = n * m;
  std::vector<int> a(nm);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i * m + j] = dist(i, j);
    }
  }
  std::sort(a.begin(), a.end());
  for (int i = 0; i < nm; ++i) {
    std::cout << a[i] << " \n"[i == nm - 1];
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
