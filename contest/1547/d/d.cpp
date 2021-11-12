#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b{0};
  for (auto& x : a) std::cin >> x;
  int cur = a[0];
  for (int i = 1; i < n; ++i) {
    cur |= a[i];
    b.emplace_back(a[i] ^ cur);
  }
  for (auto x : b) std::cout << x << ' ';
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