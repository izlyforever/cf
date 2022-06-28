#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool query(int l, int r) {
  bool flag = false;
  std::cout << "? " << l << ' ' << r << std::endl;
  for (int i = l; i <= r; ++i) {
    int x;
    std::cin >> x;
    if (x >= l && x <= r) flag = !flag;
  }
  return flag;
}

void solve() {
  int n;
  std::cin >> n;
  std::set<int> S;
  for (int i = 1; i <= n; ++i) S.insert(i);
  int l = 1, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (query(l, m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  std::cout << "! " << r << std::endl;
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
