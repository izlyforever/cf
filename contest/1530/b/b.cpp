#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n, std::string(m, '0'));
  for (int i = 0; i < n; i += 2) a[i][0] = '1';
  for (int i = 2; i < n; i += 2) a[i].back() = '1';
  for (int j = 0; j < m; j += 2) a[0][j] = '1';
  for (int j = 2; j < m; j += 2) a.back()[j] = '1';
  if (m % 2 == 0) {
    a.back()[m - 2] = '0';
  } else if (n % 2 == 0) {
    a[n - 2].back() = '0';
  }
  for (auto& x : a) std::cout << x << '\n';
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