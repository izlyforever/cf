#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
constexpr int M = 998244353;

void add(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> ans(n + 1);
  std::vector<int> a(n + 1);
  a[0] = 1;
  for (int _ = 0, cur = 0; cur <= n; ++_, ++k) {
    std::vector<int> b(n + 1);
    for (int j = k; j <= n; ++j) {
      b[j] = b[j - k];
      add(b[j], a[j - k]);
    }
    cur += k;
    std::swap(a, b);
    for (int i = 1; i <= n; ++i) {
      add(ans[i], a[i]);
    }
  }
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
