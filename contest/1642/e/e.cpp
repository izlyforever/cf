#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::set<int> S;
  for (int i = 0; i <= n + 1; ++i) S.insert(i);
  std::map<int, int> mp;
  for (int i = 0; i < q; ++i) {
    int op;
    std::cin >> op;
    if (op) {
      int j;
      std::cin >> j;
      if (!S.count(j)) {
        std::cout << "NO\n";
      } else {
        int l = *std::prev(S.find(j));
        int r = *std::next(S.find(j));
        auto it = mp.upper_bound(l);
        // there is one element in [it->first, it->second]
        if (it != mp.end() && it->second < r) {
            std::cout << "YES\n";
        } else {
            std::cout << "N/A\n";
        }
      }
    } else {
      int l, r, x;
      std::cin >> l >> r >> x;
      if (x == 0) {
        auto it = S.lower_bound(l);
        while (it != S.end() && *it <= r) {
          it = S.erase(it);
        }
      } else {
        auto it = mp.lower_bound(l);
        if (it != mp.end() && it->second <= r) continue;
        mp[l] = r;
        it = mp.find(l);
        while (it != mp.begin() && r <= std::prev(it)->second) {
          mp.erase(std::prev(it));
          it = mp.find(l);
        }
      }
    }
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