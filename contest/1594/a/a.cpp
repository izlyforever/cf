#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  LL n;
  std::cin >> n;
  n *= 2;
  LL a = n & (-n);
  LL b = n / a;
  --a;
  std::cout << (b - a) / 2 << ' ' << (b + a) / 2 << '\n';
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