#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n, 1), c(n);
  for (auto &x : c) std::cin >> x;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      c[i] += i;
    }
    int x = c[i];
    if (x == 0) {
      a[i] = 0;
    } else if (x < n) {
      a[x] = 0;
    }
  }
  for (auto x : a) std::cout << x << ' ';
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
