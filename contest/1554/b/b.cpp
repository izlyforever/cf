#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  LL ans = 1LL * n * (n - 1) - 1LL * k * (a[n] | a[n - 1]);
  for (int i = n; i; --i) {
    for (int j = i - 1; j && 1LL * i * (i - 1) > ans; --j) {
      ans = std::max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
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
