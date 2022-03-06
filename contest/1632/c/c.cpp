#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// '0b101000001001000110'
// '0b001101110101100110'

int solve() {
  int a, b;
  std::cin >> a >> b;
  int i = 20;
  while (i >= 0) {
    if ((a >> i & 1) == 1 && (b >> i & 1) == 0) break;
    --i;
  }
  if (i == -1) {
    return 1;
  }
  int ans = std::min(b - a, 1 + (a | b) - b);
  int x = a % (1 << i), y = b % (1 << i);
  ans = std::min(ans, (1 << i) - y + 1 + x);
  int j = i;
  while (a >> j & 1) ++j;
  if (b >> j & 1) {
    int cnt = (1 << i) - x;
    int na = a + cnt;
    ans = std::min(ans, cnt + (na == b ? 0 : 1));
  }
  return ans;
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
