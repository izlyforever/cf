#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int n3 = n / 3;
  if (n % 3 == 1) {
    std::cout << 1;
  }
  for (int i = 0; i < n3; ++i) {
    std::cout << 21;
  }
  if (n % 3 == 2) {
    std::cout << 2;
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
