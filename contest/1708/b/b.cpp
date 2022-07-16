#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, l, r;
  std::cin >> n >> l >> r;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = r / i * i;
    if (a[i] < l) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
  for (int i = 1; i <= n; ++i) {
    std::cout << a[i] << " \n"[i == n];
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
