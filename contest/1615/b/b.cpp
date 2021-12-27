#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int f(int n, int i) {
  int ans = (n >> i + 1) << i;
  if (n & (1 << i)) {
    ans += (1 << i) - 1;
  } else {
    ans += n & (1 << i) - 1;
  }
  return ans;
}

void solve() {
  int l, r;
  std::cin >> l >> r;
  int ans = r - l + 1;
  for (int i = 0; (1 << i) <= r; ++i) {
    ans = std::min(ans, f(r, i) - f(l - 1, i));
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