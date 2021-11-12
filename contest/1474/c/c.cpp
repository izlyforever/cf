#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  auto f = [](std::map<int, int> mp, int x) {
    std::vector<std::pair<int, int>> r;
    while (!mp.empty()) {
      auto it = mp.rbegin();
      int u = it->first;
      if (--mp[u] == 0) mp.erase(u);
      if (mp.find(x - u) == mp.end()) return std::vector<std::pair<int, int>>();
      r.emplace_back(x - u, u);
      if (--mp[x - u] == 0) mp.erase(x - u);
      x = u;
    }
    return r;
  };
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0, x; i < 2 * n; ++i) {
      std::cin >> x;
      ++mp[x];
    }
    int x;
    std::vector<std::pair<int, int>> r;
    int t = mp.rbegin()->first;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      x = t + it->first;
      r = f(mp, x);
      if (r.size()) break;
    }
    if (r.size()) {
      std::cout << "YES\n";
      std::cout << x << "\n";
      for (auto [x, y] : r) std::cout << x << " " << y << "\n";
    } else std::cout << "NO\n";
  }
  return 0;
}