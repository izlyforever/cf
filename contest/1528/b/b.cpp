#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  constexpr int M = 998244353;
  int n;
  std::cin >> n;
  std::vector<int> d(n + 1), a(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) ++d[j];
  }
  int ans = 0, sm = 0;
  for (int i = 1; i <= n; ++i) {
    ans = sm + d[i];
    if (ans >= M) ans -= M;
    sm += ans;
    if (sm >= M) sm -= M;
  }
  std::cout << ans << '\n';
  return 0;
}