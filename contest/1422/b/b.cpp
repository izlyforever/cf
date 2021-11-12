#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  auto f = [](std::vector<LL> a) -> LL {
    std::sort(a.begin(), a.end());
    LL r = 0, t = a[a.size() / 2];
    for (auto x : a) r += abs(x - t);
    return r;
  };
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    LL a[n][m];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cin >> a[i][j];
      }
    }
    int n2 = n / 2, m2 = m / 2;
    LL r = 0;
    for (int i = 0; i < n2; ++i) {
      for (int j = 0; j < m2; ++j) {
        r += f(std::vector<LL>{a[i][j], a[n - 1 - i][j], a[i][m - 1 - j], a[n - 1 - i][m - 1 - j]});
      }
    }
    if (n & 1) for (int j = 0; j < m2; ++j) r += f(std::vector<LL>{a[n2][j], a[n2][m - 1 - j]});
    if (m & 1) for (int i = 0; i < n2; ++i) r += f(std::vector<LL>{a[i][m2], a[n - 1 - i][m2]});
    print(r);
  }
  return 0;
}