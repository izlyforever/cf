#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::vector<std::string> s(n);
  for (auto& x : s) std::cin >> x;
  int ans = -1;
  std::vector<int> best(m, -1);
  for (int t = 0; t < (1 << n); ++t) {
    std::vector<int> cnt(m);
    int cur  = 0;
    for (int i = 0; i < n; ++i) {
      int sgn = (t & (1 << i)) ? 1 : -1;
      cur -= sgn * a[i];
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '1') {
          cnt[j] += sgn;
        }
      }
    }
    std::vector<int> p(m);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&cnt](int i, int j) {
      return cnt[i] < cnt[j];
    });
    for (int i = 0; i < m; ++i) {
      cur += cnt[p[i]] * (i + 1);
    }
    if (cur > ans) {
      ans = cur;
      std::swap(best, p);
    }
  }
  std::vector<int> p(m);
  for (int i = 0; i < m; ++i) p[best[i]] = i;
  for (auto x : p) std::cout << x + 1 << ' ';
  std::cout << '\n';
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