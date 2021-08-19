#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  a[n + 1] = 1;
  for (int i = 0; i <= n; ++i) {
    if (a[i] == 0 && a[i + 1] == 1) {
      for (int j = 1; j <= i; ++j) std::cout << j << ' ';
      std::cout << n + 1;
      for (int j = i + 1; j <= n; ++j) std::cout << ' ' << j;
      std::cout << '\n';
      return;
    }
  }
  std::cout << "-1\n";
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