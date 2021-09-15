#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (auto& s : a) std::cin >> s;
    std::vector<int> l(10, n), r(10, -1), u(10, n), d(10, -1), ans(10);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int t = a[i][j] - '0';
        l[t] = std::min(l[t], j);
        r[t] = std::max(r[t], j);
        u[t] = std::min(u[t], i);
        d[t] = std::max(d[t], i);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int t = a[i][j] - '0';
        ans[t] = std::max(ans[t], std::max(i, n - 1 - i) * std::max(j - l[t], r[t] - j));
        ans[t] = std::max(ans[t], std::max(j, n - 1 - j) * std::max(i - u[t], d[t] - i));
      }
    }
    for (int i = 0; i < 10; ++i) std::cout << ans[i] << " \n"[i == 9];
  }
  return 0;
}