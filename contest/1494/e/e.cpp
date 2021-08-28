#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::map<std::pair<int, int>, char> mp;
  int cnt[2]{};
  for (int i = 0; i < m; ++i) {
    char op;
    std::cin >> op;
    if (op == '?') {
      int k;
      std::cin >> k;
      std::cout << ((cnt[0] || (cnt[1] && k % 2 == 1)) ? "YES\n" : "NO\n");
    } else {
      int u, v;
      std::cin >> u >> v;
      if (op == '+') {
        char c;
        std::cin >> c;
        mp[{u, v}] = c;
        if (mp.count({v, u})) {
          ++cnt[1];
          if (mp[{v, u}] == c) ++cnt[0];
        }
      } else {
        if (mp.count({v, u})) {
          --cnt[1];
          if (mp[{v, u}] == mp[{u, v}]) --cnt[0];
        }
        mp.erase({u, v});
      }
    }
  }
  return 0;
}