#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  k %= 4;
  if (k == 0) {
    std::cout << "NO" << '\n';
    return;
  }
  std::cout << "YES" << '\n';
  if (k & 1) {
    for (int i = 1; i <= n; i += 2) {
      std::cout << i << ' ' << i + 1 << '\n';
    }
  } else {
    bool flag = true;
    for (int i = 1; i <= n; i += 2) {
      if (flag) {
        std::cout << i + 1 << ' ' << i << '\n';
      } else {
        std::cout << i << ' ' << i + 1 << '\n';
      }
      flag = !flag;
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
