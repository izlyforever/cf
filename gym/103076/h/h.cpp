#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<std::pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  auto check = [&](int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
  };
  std::map<std::string, int> mp;
  std::vector<std::string> pm;
  std::string od("012345678");
  do {
    mp[od] = pm.size();
    pm.emplace_back(od);
  } while (std::next_permutation(od.begin(), od.end()));
  std::string s(9, '0');
  for (int i = 0; i < 9; ++i) std::cin >> s[i];
  std::vector<int> c(9);
  for (int i = 1; i < 9; ++i) std::cin >> c[i];
  std::vector<LL> dist(pm.size(), INT64_MAX);
  auto Dijkstra = [&](int s) {
    dist[s] = 0;
    std::priority_queue<std::pair<LL, int>> Q;
    Q.push({0, s});
    while (!Q.empty()) {
      auto [du, u] = Q.top();
      Q.pop();
      if (dist[u] != -du) continue;
      std::string now = pm[u];
      int p0 = std::find(now.begin(), now.end(), '0') - now.begin();
      std::pair<int, int> zero{p0 / 3, p0 % 3};
      for (auto [dx, dy] : dir) if (check(zero.first + dx, zero.second + dy)) {
        int q0 = (zero.first + dx) * 3 + zero.second + dy;
        std::string cur =  now;
        std::swap(cur[p0], cur[q0]);
        int v = mp[cur], cost = c[cur[p0] - '0'];
        if (dist[v] > dist[u] + cost) {
          dist[v] = dist[u] + cost;
          Q.push({-dist[v], v});
        }
      }
    }
  };
  Dijkstra(mp["123456780"]);
  std::cout << dist[mp[s]] << '\n';
  return 0;
}