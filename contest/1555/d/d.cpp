#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, m;
  std::string s;
  std::cin >> n >> m >> s;
  std::vector<std::vector<int>> a;
  std::string x("abc");
  do {
    std::vector<int> b(n);
    for (int i = 0, now = 0, j = 0; i < n; ++i, ++j) {
      if (j == 3) j = 0;
      now += (s[i] != x[j]);
      b[i] = now;
    }
    a.emplace_back(b);
  } while (std::next_permutation(x.begin(), x.end()));
  while (m--) {
    int l, r;
    std::cin >> l >> r;
    --l; --r;
    int ans = n;
    for (int i = 0; i < 6; ++i) ans = std::min(ans, a[i][r] - (l == 0 ? 0 : a[i][l - 1]));
    std::cout << ans << '\n';
  }
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