#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<LL> s(n + 1);
  for (int i = 0; i < n; ++i) {
    s[i + 1] = s[i] + (i % 2 == 0 ? a[i] : -a[i]);
  }
  std::vector<int> p(n + 1);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&s = std::as_const(s)](int i, int j) {
    return s[i] == s[j] ? i < j : s[i] < s[j];
  });
  // This will TLE
  // auto f = [s](int i, int j) {
  //   return s[i] == s[j] ? i < j : s[i] < s[j];
  // };
  // std::sort(p.begin(), p.end(), f);
  std::set<int> g;
  for (int i = 0; i <= n; i += 2) g.insert(i);
  LL ans = 0;
  for (int l = 0, r; l <= n; l = r) {
    r = l;
    // note that s[p[i]] is monic, and l < r for this case
    while (r <= n && s[p[l]] == s[p[r]]) {
      if (p[r] % 2 == 0) g.erase(p[r]);
      ++r;
    }
    auto it = g.end();
    for (int i = l, j = 0; i < r; ++i) {
      auto jt = g.lower_bound(p[i]);
      if (it != jt) j = 0;
      it = jt;
      ans += j++;
    }
    for (int i = l; i < r; ++i) {
      if (p[i] % 2 == 1) g.insert(p[i]);
    }
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
