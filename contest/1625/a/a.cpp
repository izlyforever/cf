#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, l;
  std::cin >> n >> l;
  std::vector<int> a(l);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    for (int i = 0; i < l; ++i) {
      if (x & (1 << i)) ++a[i];
    }
  }
  int ans = 0;
  for (int i = 0; i < l; ++i) {
    if (a[i] > n - a[i]) {
      ans |= 1 << i;
    }
  }
  std::cout << ans << '\n';
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