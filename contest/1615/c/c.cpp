#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  int x = std::count(a.begin(), a.end(), '1');
  int y = std::count(b.begin(), b.end(), '1');
  auto f = [&]() {
    int ans = 0;
    for (int i = 0; i < n; ++i) if (a[i] != b[i]) ++ans;
    return ans;
  };
  auto g = [&]() {
    int ans = 0;
    for (int i = 0; i < n; ++i) if (a[i] == b[i]) ++ans;
    int t = 0;
    while (t < n && a[t] != '1' && b[t] != '1') ++t;
    if (t == n) ans += 2;
    return ans;
  };
  int ans = INT_MAX;
  if (x == y) ans = std::min(ans, f());
  if (y == n - x + 1) ans = std::min(ans, g());
  return ans == INT_MAX ? -1 : ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}