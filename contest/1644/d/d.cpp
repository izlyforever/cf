#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int M = 998244353;
const int N = 2e5 + 2;
int a[N], b[N];

int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

void solve() {
  int n, m, k, q;
  std::cin >> n >> m >> k >> q;
  std::vector<std::pair<int, int>> c(q);
  for (auto &[x, y] : c) std::cin >> x >> y;
  int nn = 0, mm = 0;
  for (int i = 1; i <= q; ++i) {
    auto [x, y] = c[q - i];
    --x; --y;
    if (nn == n || mm == m || (a[x] && b[y])) continue;
    if (a[x] == 0) {
      a[x] = i;
      ++nn;
    }
    if (b[y] == 0) {
      b[y] = i;
      ++mm;
    }
  }
  std::vector<int> cnt(q + 1);
  for (int i = 1; i <= q; ++i) {
    auto [x, y] = c[q - i];
    --x; --y;
    ++cnt[a[x]];
    ++cnt[b[y]];
    a[x] = b[y] = 0;
  }
  int ans = 0;
  for (int i = 1; i <= q; ++i) if (cnt[i]) ++ans;
  std::cout << powMod(k, ans) << '\n';
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