#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int M = 998244353;
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  std::vector<int> b{1};
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) b.emplace_back(1);
    else ++b.back();
  }
  int m = b.size();
  std::vector<int> ans{1};
  for (int i = 0, n2 = n / 2, sm = 0; i < m; ++i) {
    sm += b[i];
    int mx = std::min(n2, sm);
    std::vector<int> tmp(mx + 1);
    for (int j = ans.size() - 1; j >= 0 && ans[j]; --j) {
      for (int k = std::min(b[i], mx - j); k >= 0 && 2 * (j + k) >= sm; --k) {
        tmp[j + k] += ans[j];
        if (tmp[j + k] >= M) tmp[j + k] -= M;
      }
    }
    std::swap(ans, tmp);
  }
  int ret = ans[n / 2];
  for (auto x : b) ret = 1LL * ret * fac[x] % M;
  std::cout << ret << '\n';
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
