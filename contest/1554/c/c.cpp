#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n, m;
  std::cin >> n >> m;
  ++m;
  int ans = 0;
  for (int i = 30; i >= 0; --i) {
    if (n >= m) return ans;
    if (!(n & (1 << i))) ans += (m & (1 << i) ? 1 : 0) << i;
    n &= (1 << i) - 1;
    m &= (1 << i) - 1;
  }
  return ans;
}
//     1,000,005
// 1,010,111,000

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}