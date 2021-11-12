#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;


// 并查集 Disjoint Set Union
class DSU {
  int sz;
  std::vector<int> p;
 public:
  DSU(int n) : sz(n), p(n) { iota(p.begin(), p.end(), 0); }
  int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  }
  bool merge(int x, int y) {
    if (find(x) == find(y)) return false;
    // do something, small to big;
    --sz;
    p[p[x]] = p[y];
    return true;
  }
  int size() { return sz;}
};

// follow ideal of triple__a，乘积图的最小生成树也是贪心的做法：
// 第一张图两个点相连，需要连第二张图剩下的点的个数，此后第一张图的点就少了一个相当于
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n[2], m[2];
  std::cin >> n[0] >> m[0] >> n[1] >> m[1];
  DSU A[2]{n[0], n[1]};
  std::vector<std::tuple<int, int, int, int>> e;
  for (int op = 0; op < 2; ++op) {
    for (int i = 0; i < m[op]; ++i) {
      int u, v, w;
      std::cin >> u >> v >> w;
      e.emplace_back(w, u, v, op);
    }
  }
  std::sort(e.begin(), e.end());
  LL ans = 0;
  for (auto [w, u, v, op] : e) {
    if (A[op].merge(u, v)) {
      ans += 1LL * w * A[!op].size();
    }
  }
  std::cout << ans << '\n';
  return 0;
}