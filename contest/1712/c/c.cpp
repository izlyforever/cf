#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> pos;
  std::vector<std::vector<int>> val(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    std::cin >> x;
    pos[i] = x;
    val[x].emplace_back(i);
  }
  int end = n;
  int ans = 0;
  for (int i = n; i > 0; --i) if (!val[i].empty()) {
    int l = val[i].front(), r = val[i].back();
    if (r == end && r - l + 1 == (int)val[i].size()) {
      end = l - 1;
    } else {
      auto it = pos.lower_bound(l);
      while (it != pos.end() && it->first <= r) {
        for (auto x : val[it->second]) if (x != it->first) {
          pos.erase(x);
        }
        val[it->second].clear();
        it = pos.erase(it);
        ++ans;
      }
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
