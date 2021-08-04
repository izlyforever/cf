#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  freopen("orxor.in","r",stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::map<int, int> mp1, mp2;
  LL sm = 0;
  for (int i = 1, x; i <= n; ++i) {
    std::cin >> x;
    sm += x;
    if (x & 1) mp1[i] = x;
    else mp2[i] = x;
  }
  while (q--) {
    int op, l, r;
    std::cin >> op >> l >> r;
    if (op == 1) {
      for (auto it = mp2.lower_bound(l); it != mp2.end() && it->first <= r; ++it) {
        auto [u, v] = *it;
        sm -= v;
        sm += v | (v - 1);
        mp1.insert({u, v | (v - 1)});
      }
      mp2.erase(mp2.lower_bound(l), mp2.upper_bound(r));
    } else {
      for (auto it = mp1.lower_bound(l); it != mp1.end() && it->first <= r; ++it) {
        auto [u, v] = *it;
        sm -= (v - 1);
      }
      mp1.erase(mp1.lower_bound(l), mp1.upper_bound(r));
      for (auto it = mp2.lower_bound(l); it != mp2.end() && it->first <= r; ++it) {
        auto [u, v] = *it;
        sm -= v;
        sm += v ^ (v - 1);
        mp1.insert({u, v ^ (v - 1)});
      }
      mp2.erase(mp2.lower_bound(l), mp2.upper_bound(r));
    }
    std::cout << sm << std::endl;
  }
  return 0;
}