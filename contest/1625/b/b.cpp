#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> mp;
  int ans = n + 1;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (mp.count(x)) {
      ans = std::min(ans, i - mp[x]);
    }
    mp[x] = i;
  }
  std::cout << n - ans << '\n';
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
