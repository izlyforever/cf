#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> mp;
  int ans = 0;
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (mp[x]++) flag = false;
    if (x) ++ans;
    else flag = false;
  }
  ans += flag;
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
