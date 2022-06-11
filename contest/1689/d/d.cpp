#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int f(std::vector<std::pair<int, int>>& a, int n, int mx) {
  int l = 0, r = n - 1;
  for (auto &[x, y] : a) {
    if (mx < y) return -1;
    int t = mx - y;
    l = std::max(l, x - t);
    r = std::min(r, x + t);
    if (l > r) return -1;
  }
  return l;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> s(n);
  for (auto &x : s) std::cin >> x;
  std::vector<std::tuple<int, int, int>> mp;
  for (int i = 0; i < n; ++i) {
    int l = 0;
    while (l < m && s[i][l] == 'W') ++l;
    if (l == m) continue;
    int r = m - 1;
    while (r >= 0 && s[i][r] == 'W') --r;
    mp.emplace_back(i, l, r);
  }
  int ans = INT_MAX, ax = 0, ay = 0;
  for (int y = 0; y < m; ++y) {
    std::vector<std::pair<int, int>> a;
    for (auto [i, li, ri] : mp) {
      a.emplace_back(i, std::max(abs(li - y), abs(ri - y)));
    }
    int l = 0, r = n + m;
    while (l < r) {
      int mid = (l + r) / 2;
      if (f(a, n, mid) == -1) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    int x = f(a, n, r);
    if (ans > r) {
      ans = r;
      ax = x;
      ay = y;
    }
  }
  std::cout << ax + 1 << ' ' << ay + 1 << '\n';
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
