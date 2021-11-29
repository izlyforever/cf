#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int ans = 0;
  for (int i = 0; i < 30; ++i) {
    int cnt = 0;
    for (auto x : a) if (x & (1 << i)) ++cnt;
    ans = std::gcd(ans, cnt);
  }
  for (int i = 1; i <= n; ++i) if (ans % i == 0) {
    std::cout << i << ' ';
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