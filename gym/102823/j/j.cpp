#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), vis(n), r(n);
  for (auto &x : a) std::cin >> x;
  for (int i = 0; i < n; ++i) {
    if ((i == 0 || a[i] < a[i - 1]) && (i == n - 1 || a[i] < a[i + 1])) vis[i] = 1;
  }
  for (int i = 1; i < n; ++i) if (!vis[i]) {
    if (a[i] > a[i - 1]) r[i] = r[i - 1] + 1;
  }
  for (int i = n - 2; i >= 0; --i) if (!vis[i]) {
    if (a[i] > a[i + 1]) r[i] = std::max(r[i], r[i + 1] + 1);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += (a[i] - r[i]) % 2;
  return ans % 2;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  for (int T = 1; T <= cas; ++T) {
    std::cout << "Case " << T << ": " << (solve() ? "Alice" : "Bob") << "\n";
  }
  return 0;
}