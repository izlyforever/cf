#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) std::swap(a[i], b[i]);
  }
  LL r = 0;
  for (int i = 1; i < n; ++i) r += abs(a[i - 1] - a[i]);
  for (int i = 1; i < n; ++i) r += abs(b[i - 1] - b[i]);
  std::cout << r << '\n';
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
