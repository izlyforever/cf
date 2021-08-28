#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (auto &x : a) std::cin >> x;
    std::vector<std::vector<int>> b(n, std::vector<int>(m)), c(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) if (a[i][0] == '*') b[i][0] = 1;
    for (int i = 0; i < n; ++i) if (a[i][m - 1] == '*') c[i][m - 1] = 1;
    for (int j = 0; j < m; ++j) if (a[0][j] == '*') b[0][j] = c[0][j] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) if (a[i][j] == '*') {
        b[i][j] = std::min(b[i - 1][j], b[i][j - 1]) + 1;
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = m - 2; j >= 0; --j) if (a[i][j] == '*') {
        c[i][j] = std::min(c[i - 1][j], c[i][j + 1]) + 1;
      }
    }
    int r = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        r += std::min(b[i][j], c[i][j]);
      }
    }
    std::cout << r << std::endl;
  }
  return 0;
}