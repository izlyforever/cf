#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  LL cnt[2]{};
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x < 2) ++cnt[x];
  }
  std::cout << (cnt[1] << cnt[0]) << '\n';
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