#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::string s;
  std::cin >> n >> q >> s;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> plus(2 * n + 1), minus(2 * n + 1);
  for (int i = 1; i <= n; ++i) {
    if ((s[i - 1] == '+') ^ (i & 1)) {
      a[i] = a[i - 1] + 1;
      plus[n + a[i]].emplace_back(i);
    } else {
      a[i] = a[i - 1] - 1;
      minus[n + a[i]].emplace_back(i);
    }
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (a[l - 1] == a[r]) {
      std::cout << 0 << '\n';
      continue;
    }
    int ans = 1;
    if ((r - l) % 2) {
      ans = 2;
      --r;
    }
    std::cout << ans << '\n';
    int x = (a[r] - a[l - 1] + 1) / 2 + a[l - 1] + n;
    auto it = std::lower_bound(plus[x].begin(), plus[x].end(), l);
    if (it != plus[x].end() && *it <= r) {
      std::cout << *it;
    } else {
      --x;
      auto it2 = std::lower_bound(minus[x].begin(), minus[x].end(), l);
      if (it2 != minus[x].end()) {
        std::cout << *it2;
      }
    }
    if (ans == 2) std::cout << ' ' << ++r;
    std::cout << '\n';
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
