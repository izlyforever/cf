#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n, T;
    std::cin >> n >> T;
    std::vector<std::pair<int, int>> a;
    std::vector<bool> vis(n);
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      a.push_back({x, i});
    }
    std::sort(a.begin(), a.end());
    if (T % 2 == 0) {
      int id1 = std::lower_bound(a.begin(), a.end(), std::make_pair(T / 2, -1)) - a.begin();
      int id2 = std::lower_bound(a.begin(), a.end(), std::make_pair(T / 2 + 1, -1)) - a.begin();
      id2 = (id1 + id2) / 2;
      for (int i = 0; i < id2; ++i) vis[a[i].second] = 1;
    } else {
      int id = std::lower_bound(a.begin(), a.end(), std::make_pair(T / 2 + 1, -1)) - a.begin();
      for (int i = 0; i < id; ++i) vis[a[i].second] = 1;
    }
    for (auto x : vis) std::cout << x << " ";
    println;
  }
  return 0;
}