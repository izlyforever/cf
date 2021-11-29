#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int M = 998244353;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), l(n + 2, 1), r(n + 2, 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) l[i] = 1LL * l[i - 1] * a[i] % M;
  for (int i = n; i >= 1; --i) r[i] = 1LL * r[i + 1] * a[i] % M;
  for (int i = 1; i <= n; ++i) {
    std::cout << 1LL * l[i - 1] * r[i + 1] % M << " \n"[i == n];
  }
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