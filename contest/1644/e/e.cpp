#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int cnt0 = std::count(s.begin(), s.end(), s[0]);
  int cnt[2]{cnt0, (int)s.size() - cnt0};
  if (cnt[0] == 0 || cnt[1] == 0) {
    std::cout << n << '\n';
    return;
  }
  int c = 1;
  while (s[c] == s[0]) ++c;
  // we may assum s[0] = R, then c line blew will not visit
  LL ans = n * n - 1LL * c * (n - 1);
  ans -= 1LL * (cnt[s[0] != 'D'] - c) * cnt[s[0] == 'D'];
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