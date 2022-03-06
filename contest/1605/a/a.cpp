#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::vector<int> a(3);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  int x = abs(a[0] + a[2] - 2 * a[1]);
  std::cout << (x % 3 != 0) << '\n';
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
