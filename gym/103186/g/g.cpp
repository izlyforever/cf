#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

const int M = 998244353;
int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), ans(n);
  int r = 1, cnt = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] == M) {
      ++cnt;
    } else {
      r = 1LL * r * a[i] % M;
    }
  }
  if (cnt == 0) {
    for (int i = 0; i < n; ++i) ans[i] = 1LL * powMod(a[i], M - 2) * r % M;
  } else if (cnt == 1) {
    for (int i = 0; i < n; ++i) if (a[i] == M) {
      ans[i] = r;
      break;
    }
  }
  for (int i = 0; i < n; ++i) std::cout << ans[i] << ' ';
  std::cout << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}