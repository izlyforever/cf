#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  // 从 1 开始标号会方便很多
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  auto f = [&](int m) {
    std::vector<int> b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) b[i] = (a[i] >= m ? 1 : -1);
    for (int i = 1; i <= n; ++i) b[i] += b[i - 1];
    for (int i = 1; i <= n; ++i) {
      c[i] = std::min(c[i - 1], b[i]);
    }
    for (int i = k; i <= n; ++i) if (b[i] > c[i - k]) return true;
    return false;
  };
  int l = 1, r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    if (f(m)) l = m + 1;
    else r = m - 1;
  }
  std::cout << r << "\n";
  return 0;
}
