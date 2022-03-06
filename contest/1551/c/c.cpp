#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (auto& x : a) std::cin >> x;
  auto f = [&](char c) -> int {
    auto len = [&](const std::string& s) -> int {
      return 2 * (int)std::count(s.begin(), s.end(), c) - (int)s.size();
    };
    std::sort(a.begin(), a.end(), [&](const std::string& x, const std::string& y) {
      return len(x) > len(y);
    });
    for (int i = 0, x = 0; i < n; ++i) {
      x += len(a[i]);
      if (x <= 0) return i;
    }
    return n;
  };
  int ans = 0;
  for (char c = 'a'; c != 'f'; ++c) ans = std::max(ans, f(c));
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
