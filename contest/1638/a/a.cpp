#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != i) {
      int j = i;
      while (a[j] != i) ++j;
      std::reverse(a.begin() + i, a.begin() + j + 1);
      break;
    }
  }
  for (int i = 1; i <= n; ++i) std::cout << a[i] << " \n"[i == n];
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
