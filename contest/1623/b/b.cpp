#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::set<int>> left(n + 1);
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    left[r].insert(l);
  }
  for (int i = 1; i <= n; ++i) {
    while (!left[i].empty()) {
      int now = *left[i].begin();
      left[i].erase(left[i].begin());
      std::cout << now << ' ' << i << ' ' << (left[i].empty() ? i : *left[i].begin() - 1) << '\n';
    }
  }
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