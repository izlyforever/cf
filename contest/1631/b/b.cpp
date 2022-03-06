#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::reverse(a.begin(), a.end());
  int a0 = a[0];
  int now = 0;
  while (now < n && a[now] == a0) ++now;
  int ans = 0;
  while (now < n) {
    ++ans;
    now *= 2;
    while (now < n && a[now] == a0) ++now;
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
