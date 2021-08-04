#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      p[--x] = i;
    }
    if (n == 1) {
      std::cout << "0\n";
      continue;
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
      std::set<std::pair<int, int>> S;
      for (int j = i; j < n; ++j) {
        int l = p[j], r = p[j];
        auto it = S.upper_bound({l, r});
        if (it != S.end() && it->first == l + 1) {
          r = it->second;
          S.erase(it);
          it = S.upper_bound({l, r});
        }
        if (it != S.begin()) {
          --it;
          if (it->second + 1 == l) {
            l = it->first;
            S.erase(it);
          }
        }
        S.insert({l, r});
        if (S.size() <= 2) ++ans;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}