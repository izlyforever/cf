#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), p(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  for (int i = 0; i < n; ++i) {
    p[--a[i]] = --b[i];
  }
  std::vector<int> vis(n), cnt;
  for (int i = 0; i < n; ++i) if (!vis[i]) {
    int u = i, t = 0;
    do {
      vis[u] = 1;
      ++t;
      u = p[u];
    } while (u != i);
    if (t > 1) cnt.emplace_back(t / 2 * 2);
  }
  LL ans = 0;
  int l = 0, r = n - 1;
  for (auto x : cnt) {
    int t = l, last = -1;
    for (int i = 0; i < x; ++i) {
      if (i & 1) {
        ans += r - last;
        last = r--;
      } else {
        if (last != -1) {
          ans += last - l;
        }
        last = l++;
      }
    }
    ans += last - t;
  }
  std::cout << ans << '\n';
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
