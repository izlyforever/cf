#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
const int M = 998244353;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), sa(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) sa[i] = std::sqrt(a[i]) + 1;
  int ans = 0;
  std::vector<int> big(sa[n]), small(a[n] / sa[n] + 1);
  big[1] = 1;
  for (int i = n - 1; i > 0; --i) {
    int sai = sa[i];
    std::vector<int> bigNew(sai), smallNew(a[i] / sai + 1);
    bigNew[1] = 1;
    for (int j = 1, sb = (int)big.size(), last = a[i + 1]; j < sb; ++j) {
      int x = last / j;
      int t = (a[i] + x - 1) / x;
      ans = (ans + 1LL * (t - 1) * i % M * big[j]) % M;
      if (t < sai) bigNew[t] += big[j];
      else smallNew[a[i] / t] += big[j];
    }
    for (int j = 1, ss = (int)small.size(); j < ss; ++j) {
      int t = (a[i] + j - 1) / j;
      ans = (ans + 1LL * (t - 1) * i % M * small[j]) % M;
      if (t < sai) bigNew[t] += small[j];
      else smallNew[a[i] / t] += small[j];
    }
    std::swap(big, bigNew);
    std::swap(small, smallNew);
  }
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}
