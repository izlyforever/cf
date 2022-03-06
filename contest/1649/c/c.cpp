#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 1e5 + 2;

LL f(std::vector<int>& a) {
  std::sort(a.begin(), a.end());
  LL ans = 0, sm = 0;
  for (int i = 0, n = a.size(); i < n; ++i) {
    ans += 1LL * i * a[i] - sm;
    sm += a[i];
  }
  return ans;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  int nm = n * m;
  std::vector<std::vector<std::pair<int, int>>> c(N);
  for (int i = 0; i < n; ++i) {
    for (int j = 0, x; j < m; ++j) {
      std::cin >> x;
      c[x].emplace_back(i, j);
    }
  }
  std::vector<int> a, b;
  a.reserve(nm);
  b.reserve(nm);
  LL ans = 0;
  for (int i = 0; i < N; ++i) if (c[i].size() > 1) {
    for (auto [x, y] : c[i]) {
      a.emplace_back(x);
      b.emplace_back(y);
    }
    ans += f(a);
    ans += f(b);
    a.clear();
    b.clear();
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
