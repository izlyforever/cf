#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int dist2(std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
  auto [xa, ya, za] = a;
  auto [xb, yb, zb] = b;
  xa -= xb; ya -= yb; za -= zb;
  return xa * xa + ya * ya + za * za;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::vector<std::tuple<int, int, int>> a(8);
    for (auto& [x, y, z] : a) std::cin >> x >> y >> z;
    std::vector<std::vector<int>> dist(8, std::vector<int>(8));
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        dist[i][j] = dist2(a[i], a[j]);
      }
    }
    auto check = [&]() {
      for (int i = 0; i < 8; ++i) std::sort(dist[i].begin(), dist[i].end());
      int x = dist[0][1];
      if (x == 0) return false;
      for (int i = 0; i < 8; ++i) {
        for (int j = 1; j < 4; ++j) {
          if (dist[i][j] != x) return false;
        }
        for (int j = 4; j < 7; ++j) {
          if (dist[i][j] != 2 * x) return false;
        }
        if (dist[i].back() != 3 * x) return false;
      }
      return true;
    };
    std::cout << (check() ? "YES" : "NO") << '\n';
  }
  return 0;
}