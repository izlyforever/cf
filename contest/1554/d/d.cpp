#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  if (n & 1) {
    std::cout << 'c';
    --n;
  }
  if (n) {
    --n;
    std::cout << std::string(n / 2, 'a');
    std::cout << 'b';
    std::cout << std::string(n - n / 2, 'a');
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
