#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    LL mx[5][n], mi[5][n];
    mx[0][0] = mi[0][0] = a[0];
    for (int i = 1; i < 5; ++i) mi[i][i] = mx[i][i] = mx[i - 1][i - 1] * a[i];
    for (int i = 1; i < n; ++i) mx[0][i] = std::max(mx[0][i - 1], LL(a[i]));
    for (int i = 1; i < n; ++i) mi[0][i] = std::min(mi[0][i - 1], LL(a[i]));
    for (int i = 1; i < 5; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (a[j] >= 0) {
          mx[i][j] = std::max(mx[i][j - 1], mx[i - 1][j - 1] * a[j]);
          mi[i][j] = std::min(mi[i][j - 1], mi[i - 1][j - 1] * a[j]);
        } else {
          mx[i][j] = std::max(mx[i][j - 1], mi[i - 1][j - 1] * a[j]);
          mi[i][j] = std::min(mi[i][j - 1], mx[i - 1][j - 1] * a[j]);
        }
      }
    }
    std::cout << mx[4][n - 1] << std::endl;
  }
  return 0;
}