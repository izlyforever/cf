#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  if ((n + 1) / 2 >= k) {
    std::vector<std::string> a(n, std::string(n, '.'));
    for (int i = 0; i < 2 * k; i += 2) {
      a[i][i] = 'R';
    }
    for (auto &x : a) std::cout << x << '\n';
  } else {
    std::cout << -1 << '\n';
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