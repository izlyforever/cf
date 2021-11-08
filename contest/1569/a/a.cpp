#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::string a;
  std::cin >> n >> a;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      std::cout << i << ' ' << i + 1 << '\n';
      return;
    }
  }
  std::cout << -1 << ' ' << -1 << '\n';
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