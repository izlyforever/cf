#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int cnt = 0, ans = 0;
  std::optional<char> last;
  for (int i = 0; i < n; i += 2) {
    if (s[i] == s[i + 1]) {
      if (!last.has_value() || last != s[i]) {
        last = s[i];
        ++ans;
      }
    } else {
      ++cnt;
    }
  }
  std::cout << cnt << ' ' << std::max(1, ans) << '\n';
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
