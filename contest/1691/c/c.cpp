#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  int r = n - 1;
  while (r >= 0 && s[r] == '0') --r;
  if (r == -1) {
    std::cout << 0 << '\n';
    return;
  }
  int ans = 11 * std::count(s.begin(), s.end(), '1');
  int l = 0;
  while (l < n && s[l] == '0') ++l;
  if (l == r) {
    if (k >= n - 1 - r) {
      ans -= 10;
    } else if (k >= l) {
      ans -= 1;
    }
  } else {
    if (k >= n - 1 - r) {
      k -= n - 1 - r;
      ans -= 10;
    }
    if (k >= l) {
      k -= l;
      ans -= 1;
    }
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
