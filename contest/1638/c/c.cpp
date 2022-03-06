#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n), a(n);
  std::iota(p.begin(), p.end(), 0);
  for (auto &x : a) std::cin >> x;
  for (auto &x : a) --x;
  std::function<int(int)> find = [&](int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  };
  auto merge = [&](int x, int y) {
    if (find(x) != find(y)) {
      p[p[x]] = p[y];
    }
  };
  std::map<int, int> mp;
  for (int i = n - 1; i >= 0; --i) {
    auto it = mp.lower_bound(-a[i]);
    if (it != mp.end()) {
      for (int j = i; j <= it->second; ++j) {
        merge(i, j);
      }
    }
    mp[-a[i]] = i;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) if (p[i] == i) ++ans;
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
