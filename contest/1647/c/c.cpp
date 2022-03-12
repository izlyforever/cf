#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int f(char x) {
  return x - '0';
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (auto &x : a) std::cin >> x;
  if (f(a[0][0])) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<std::tuple<int, int, int, int>> ans;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j > 0; --j) if (f(a[i][j])) {
      ans.emplace_back(i + 1, j, i + 1, j + 1);
    }
    if (f(a[i][0])) {
      ans.emplace_back(i, 1, i + 1, 1);
    }
  }
  std::cout << ans.size() << '\n';
  for (auto &[x1, y1, x2, y2] : ans) {
    std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
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
