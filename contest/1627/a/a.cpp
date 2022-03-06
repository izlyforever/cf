#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n, m, r, c;
  std::cin >> n >> m >> r >> c;
  --r; --c;
  std::vector<std::string> a(n);
  for (auto & x : a) std::cin >> x;
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += std::count(a[i].begin(), a[i].end(), 'B');
  if (ans == 0) return -1;
  if (a[r][c] == 'B') return 0;
  for (int i = 0; i < n; ++i) if (a[i][c] == 'B') return 1;
  for (int i = 0; i < m; ++i) if (a[r][i] == 'B') return 1;
  return 2;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
