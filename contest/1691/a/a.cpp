#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  int cnt[2]{};
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++cnt[x & 1];
  }
  std::cout << std::min(cnt[0], cnt[1]) << '\n';
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
