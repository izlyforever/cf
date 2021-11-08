#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n), b(n - 1);
  for (auto& x : a) std::cin >> x;
  if (n == 1) {
    std::cout << 1 << '\n';
    return;
  }
  for (int i = 1; i < n; ++i) b[i - 1] = abs(a[i] - a[i - 1]);
  int ans = 0;
  std::function<void(int, int)> dfs = [&](int l, int r) {
    if (r - l <= ans) return;
    if (r - l == 1) {
      if (b[l] != 1) ans = r - l;
    } else {
      int m = (l + r) / 2;
      if (b[m] != 1) {
        std::vector<LL> L{b[m]}, R{b[m]};
        for (int i = m - 1; i >= l; --i) {
          auto now = std::gcd(L.back(), b[i]);
          if (now == 1) break;
          L.emplace_back(now);
        }
        ans = std::max(ans, (int)L.size());
        for (int i = m + 1; i < r; ++i) {
          auto now = std::gcd(R.back(), b[i]);
          if (now == 1) break;
          R.emplace_back(now);
        }
        ans = std::max(ans, (int)R.size());
        for (int i = 0, j = R.size() - 1, nl = L.size(); i < nl; ++i) {
          while (std::gcd(R[j], L[i]) == 1) --j;
          ans = std::max(ans, i + 1 + j);
        }
      }
      dfs(l, m);
      if (m + 1 < r) dfs(m + 1, r);
    }
  };
  dfs(0, n - 1);
  std::cout << ++ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}