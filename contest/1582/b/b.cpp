#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  LL cnt[2]{};
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x < 2) ++cnt[x];
  }
  std::cout << (cnt[1] << cnt[0]) << '\n';
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