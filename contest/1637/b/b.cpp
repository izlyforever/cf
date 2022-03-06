#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int f(std::vector<int> a) {
  int n = a.size();
  std::vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::set<int> S;
    int mx = 0;
    for (int j = i - 1; j >= 0; --j) {
      S.insert(a[j]);
      while (S.count(mx)) ++mx;
      dp[i] = std::max(dp[i], dp[j] + mx);
    }
    ++dp[i];
  }
  int ans = 0, mx = 0;
  for (int i = 1; i <= n; ++i) {
    mx = std::max(mx, dp[i]);
    ans += mx;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += f(std::vector<int>(a.begin() + i, a.end()));
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
