#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int ans = 0, i = 0;
  while (i < n && s[i] == '1') ++i;
  while (i < n) {
    int j = i + 1;
    while (j < n && s[j] == '1') ++j;
    if (j == n) break;
    ans += std::max(0, 3 - (j - i));
    i = j;
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
