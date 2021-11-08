#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    int n, h, s;
    std::cin >> n >> h >> s;
    std::vector<std::vector<LL>> f(h + 1, std::vector<LL>(s + 1));
    for (int _ = 0; _ < n; ++_) {
      int x, y, w;
      std::cin >> x >> y >> w;
      for (int i = h; i > x; --i) {
        for (int j = s; j > y; --j) {
          f[i][j] = std::max(f[i][j], f[i - x][j - y] + w);
        }
        for (int j = std::min(s, y); j >= 0 && i - x + j - y > 0; --j) {
          f[i][j] = std::max(f[i][j], f[i - x + j - y][0] + w);
        }
      }
    }
    std::cout << f[h][s] << '\n';
  }
  return 0;
}