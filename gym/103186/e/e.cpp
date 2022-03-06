#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::map<char, int> mp{{'D', 16}, {'C', 24}, {'B', 54}, {'A', 80}, {'S', 10000}};
  int n, k;
  std::cin >> n >> k;
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    char x;
    double p;
    std::cin >> x >> p;
    ans += mp[x] * p;
  }
  std::cout << std::fixed << (ans - 23) * k << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  std::cout.precision(12);
  while (cas--) {
    solve();
  }
  return 0;
}
