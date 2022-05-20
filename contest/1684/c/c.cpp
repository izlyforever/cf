#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

std::pair<int, int> f(const std::vector<int>& a) {
  int n = a.size();
  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return a[i] == a[j] ? i < j : a[i] < a[j];
  });
  int l = -1, r = -1;
  for (int i = 0; i < n; ++i) if (p[i] != i && a[p[i]] != a[i]) {
    if (l == -1) {
      l = i;
    } else {
      r = i;
    }
  };
  return {l, r};
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (auto &x : a) for (auto &i : x) std::cin >> i;
  auto check = [&]() {
    for (auto &x : a) if (!std::is_sorted(x.begin(), x.end())) return false;
    return true;
  };
  std::pair<int, int> ans{-1, -1};
  [&]() {
    for (auto &b : a) {
      auto [x, y] = f(b);
      if (x != -1) {
        for (int i = 0; i < n; ++i) std::swap(a[i][x], a[i][y]);
        ans = {x + 1, y + 1};
        return;
      }
    }
  }();
  if (check()) {
    auto [x, y] = ans;
    if (x != -1) {
      std::cout << x << ' ' << y << '\n';
    } else {
      std::cout << 1 << ' ' << 1 << '\n';
    }
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
