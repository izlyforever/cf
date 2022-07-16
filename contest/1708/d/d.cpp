#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++mp[x];
  }
  for (int i = 1; i < n; ++i) {
    auto it = mp.begin();
    int last = it->first;
    if (last == 0) {
      if (--mp[0] == 0) {
        it = mp.erase(it);
      } else {
        ++it;
      }
    } else {
      if (it->second > 1) {
        mp[0] += it->second - 1;
      }
      it = mp.erase(it);
    }
    while (it != mp.end()) {
      auto [u, v] = *it;
      it = mp.erase(it);
      int ul = u - last;
      ++mp[ul];
      if (v > 1) mp[0] += v - 1;
      last = u;
    }
  }
  std::cout << mp.begin()->first << '\n';
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
