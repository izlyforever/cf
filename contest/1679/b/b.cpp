#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  LL ans = 0;
  int last = -1;
  std::map<int, int> mp;
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    mp[i] = x;
    ans += x;
  }
  auto get = [&](int i) {
    if (mp.count(i)) return mp[i];
    return last;
  };
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int i, x;
      std::cin >> i >> x;
      int y = get(i);
      ans += x - y;
      mp[i] = x;
    } else {
      int x;
      std::cin >> x;
      mp.clear();
      last = x;
      ans = 1LL * n * x;
    }
    std::cout << ans << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
