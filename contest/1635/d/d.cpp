#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int M = 1e9 + 7;

void add(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}

void solve() {
  int n, p;
  std::cin >> n >> p;
  std::vector<int> tmp(n);
  for (auto &x : tmp) std::cin >> x;
  std::sort(tmp.begin(), tmp.end());
  std::set<int> S;
  auto f = [&S](int x) -> bool {
    while (x > 0) {
      if (S.count(x)) return true;
      if (x % 4 == 0) x /= 4;
      else if (x % 2 == 1) x /= 2;
      else break;
    }
    return false;
  };
  for (auto x : tmp) {
    if (!f(x)) S.insert(x);
  }
  std::vector<int> a(p);
  for (auto &x : S) {
    int lgx = std::__lg(x);
    if (lgx < p) ++a[lgx];
  }
  int ans = 0;
  for (int i = 0; i < p; ++i) {
    if (i >= 1) {
      add(a[i], a[i - 1]);
      if (i >= 2) {
        add(a[i], a[i - 2]);
      }
    }
    add(ans, a[i]);
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}