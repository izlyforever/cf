#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1), ans(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> p[i];
  std::string s;
  std::cin >> s;
  std::map<int, int> a, b;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      a[p[i + 1]] = i + 1;
    } else {
      b[p[i + 1]] = i + 1;
    }
  }
  int now = 0;
  for (auto [x, pos] : a) {
    ans[pos] = ++now;
  }
  for (auto [x, pos] : b) {
    ans[pos] = ++now;
  }
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
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