#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int x;
  std::cin >> x;
  int a[4];
  for (int i = 1; i <= 3; ++i) std::cin >> a[i];
  for (int i = 1; i <= 3; ++i) {
    if (x == 0) {
      std::cout << "NO\n";
      return;
    }
    x = a[x];
  }
  std::cout << "YES\n";
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
