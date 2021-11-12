#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::string a;
  std::cin >> n >> a;
  auto s = a;
  std::sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) if (a[i] != s[i]) ++ans;
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