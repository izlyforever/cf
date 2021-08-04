#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
bool solve() {
  int n;
  std::cin >> n;
  std::vector<LL> d(2 * n);
  for (auto &x : d) std::cin >> x;
  std::sort(d.begin(), d.end());
  for (int i = 0; i < n; ++i) if (d[i * 2] != d[i * 2 + 1]) return 0;
  std::vector<LL> a(n + 1);
  for (int i = 0; i < n; ++i) {
    if (d[i * 2] % 2 == 1) return 0;
    a[i + 1] = d[i * 2] / 2;
  }
  LL s = 0;
  for (int i = n; i > 0; --i) {
    if (a[i] <= 0 || a[i] % i != 0) return 0;
    a[i] /= i;
    s += a[i];
    a[i - 1] -= s;
  }
  for (int i = 1; i < n; ++i) if (a[i] >= a[i + 1]) return 0;
  return 1;
}
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}