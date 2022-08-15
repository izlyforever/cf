#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1, 1);
  for (int i = n; i > 1; i -= 2) {
    a[i] = i - 1;
    a[i - 1] = i;
  }
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
