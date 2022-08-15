#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// 2k = lcm(i, j, k) ==> k < i + j
// j = 2k / 3
// 2k / 3 > i > 2k / 6, factor of 2 * k;
// Thus i = 2k / 4, 2k / 5
// thus l <= k <= r, 6 | k or 15 | k note that l <= i
// 2k / 5 >= l, k >= 5 * l / 2

const int N = 2e5 + 2;

LL C3(int l, int r) {
  int x = r - l;
  return 1LL * (x + 1) * x * (x - 1) / 6;
}

void solve() {
  int l, r;
  std::cin >> l >> r;
  LL ans = C3(l, r);
  std::vector<int> cnt(N);
  for (int i = l; i <= r; ++i) {
    for (int j = i * 2; j <= r; j += i) {
      ++cnt[j];
    }
  }
  for (int k = l; k <= r; ++k) {
    ans -= 1LL * cnt[k] * (cnt[k] - 1) / 2;
  }
  ans -= std::max(0, r / 6 - (l - 1) / 3);
  ans -= std::max(0, r / 15 - (l - 1) / 6);
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
