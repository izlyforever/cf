#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  if (n == 1 || s[0] == s[1]) {
    std::cout << s[0] << s[0] << '\n';
    return;
  }
  int now = 1;
  while (now < n && s[now] <= s[now - 1]) ++now;
  for (int i = 0; i < now; ++i) std::cout << s[i];
  for (int i = now - 1; i >= 0; --i) std::cout << s[i];
  std::cout << '\n';
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
