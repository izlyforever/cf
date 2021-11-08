#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  std::string a;
  std::cin >> a;
  int cnt[26] {}, ans = 0;
  for (auto x : a) {
    if (cnt[x - 'a']++ < 2) ++ans;
  }
  std::cout << ans / 2 << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}