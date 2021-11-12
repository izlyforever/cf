#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int M = 1e5;
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m + 1, -1);
  a[0] = 0;
  for (int i = 1; i <= n; ++i) {
    LL xx;
    int op, y;
    std::cin >> op >> xx >> y;
    if (op == 1) {
      int x = (xx + M - 1) / M;
      for (int j = m; j >= 0; --j) if (a[j] != -1) {
        for (int k = 1, t = j + x; k <= y && t <= m && a[t] == -1; ++k, t += x) {
          a[t] = i;
        }
      }
    } else {
      for (int j = m; j >= 0; --j) if (a[j] != -1) {
        LL t = (xx * j + M - 1) / M;
        for (int k = 1; k <= y && t <= m && a[t] == -1; ++k, t = (xx * t + M - 1) / M) {
          a[t] = i;
        }
      }
    }
  }
  for (int i = 1; i <= m; ++i) std::cout << a[i] << " \n"[i == m];
  return 0;
}