#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> s >> k;
  int cnt[26]{};
  for (int i = 0; i < k; ++i) {
    char x;
    std::cin >> x;
    ++cnt[x - 'a'];
  }
  int ans = 0;
  for (int i = n - 1, lt = n; i >= 0; --i) {
    if (lt < n) {
      ans = std::max(ans, lt - i);
    }
    if (cnt[s[i] - 'a']) lt = i;
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
