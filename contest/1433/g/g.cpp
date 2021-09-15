#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  auto cmin = [](auto& x, auto y) {
    if (x > y) x = y;
  };
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> d(n, std::vector<int>(n, 1e9));
  for (int i = 0; i < n; ++i) d[i][i] = 0;
  std::vector<std::tuple<int, int, int>> road(m);
  for (auto& [x, y, w] : road) {
    std::cin >> x >> y >> w;
    --x; --y;
    cmin(d[x][y], w);
    d[y][x] = d[x][y];
  }
  std::vector<std::pair<int, int>> travel(k);
  for (auto& [a, b] : travel) {
    std::cin >> a >> b;
    --a; --b;
  }
  auto floyd = [&](){
    for(int k = 0; k != n; ++k)
      for(int i = 0; i != n; ++i)
        for(int j = 0; j != n; ++j)
          cmin(d[i][j], d[i][k] + d[k][j]);
  };
  floyd();
  LL r = 1e9;
  for (auto [x, y, w] : road) {
    LL now = 0;
    for (auto [a, b] : travel) {
      now += std::min({d[a][b], d[a][x] + d[y][b], d[a][y] + d[x][b]});
    }
    cmin(r, now);
  }
  print(r);
  return 0;
}
