#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, m;
  std::cin >> n >> m;
  int last = 0;
  for (int i = 1; i <= n; ++i) if (!__builtin_parity(i)) {
    if (i - m > last) last = i;
  }
  std::cout << (last != n ? "Pay the bill" : "Free snacks!") << '\n';
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