#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int M = 998244353;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int ans = 1;
  std::function<std::string(int)> dfs = [&](int x) -> std::string {
    std::string ret(1, s[x]);
    if (2 * x + 1 < (int)s.size()) {
      auto p1 = dfs(2 * x + 1);
      auto p2 = dfs(2 * (x + 1));
      if (p1 != p2) {
        ans *= 2;
        if (ans >= M) ans -= M;
      }
      if (p1 > p2) std::swap(p1, p2);
      ret += p1 + p2;
    }
    return ret;
  };
  dfs(0);
  std::cout << ans << '\n';
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
