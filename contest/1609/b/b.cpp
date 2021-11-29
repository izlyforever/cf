#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string s;
  int n, m;
  std::cin >> n >> m >> s;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s.substr(i, 3) == "abc") ++ans;
  }
  while (m--) {
    int id;
    char c;
    std::cin >> id >> c;
    --id;
    for (int i = std::max(0, id - 2); i <= id; ++i) {
      if (s.substr(i, 3) == "abc") --ans;
    }
    s[id] = c;
    for (int i = std::max(0, id - 2); i <= id; ++i) {
      if (s.substr(i, 3) == "abc") ++ans;
    }
    std::cout << ans << '\n';
  }
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