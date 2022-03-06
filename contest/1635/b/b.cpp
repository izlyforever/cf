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
  auto b = a;
  int ans = 0, last = -1;
  for (int i = 2; i < n; ++i) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      if (i - last == 2) {
        b[i - 1] = std::max(a[i - 2], a[i]);
        last = -1;
      } else {
        if (last != -1) {
          b[last] = std::max(a[last - 1], a[last + 1]);
          last = -1;
        }
        ++ans;
        last = i;
      }
    }
  }
  if (last != -1) {
    b[last] = std::max(a[last - 1], a[last + 1]);
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= n; ++i) std::cout << b[i] << " \n"[i == n];
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
