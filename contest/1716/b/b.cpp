#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::cout << n << '\n';
  for (int i = 1; i <= n; ++i) std::cout << i << " \n"[i == n];
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= i; ++j) std::cout << j << ' ';
    std::cout << 1 << ' ';
    for (int j = i + 1; j <= n; ++j) std::cout << j << " \n"[j == n];
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
