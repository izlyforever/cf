#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  --x;
  std::vector<int> a(n);
  int m;
  for (auto &x : a) std::cin >> x;
  std::cin >> m;
  std::vector<int> b(m);
  for (auto &x : b) std::cin >> x;
  auto check = [&](int i, int num) -> bool {
    if (i < 0 || i >= n) return false;
    return a[i] == num;
  };
  auto checkDir = [&](int dir) -> bool {
    for (int i = 1; i <= m; ++i) {
      if (!check(x + dir * i, b[i - 1])) return false;
    }
    return true;
  };
  if (checkDir(1) && checkDir(-1)) {
    std::cout << "Unsure" << '\n';
  } else {
    std::cout << (checkDir(x > y ? -1 : 1) ? "Right" : "Wrong") << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}