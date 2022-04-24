#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ans ^= (x - 1);
  }
  std::cout << (ans & 1 ? "errorgorn" : "maomao90") << '\n';
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
