#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n, d;
  std::cin >> n >> d;
  std::vector<int> p(n), sz(n, 1);
  std::iota(p.begin(), p.end(), 0);
  std::function<int(int)> find = [&](int x) -> int {
    return x == p[x] ? x : p[x] = find(p[x]);
  };
  std::multiset<std::pair<int, int>> left;
  std::set<int> leftId;
  for (int i = 0; i < n; ++i) left.emplace(-sz[i], i);
  for (int i = 0; i < n; ++i) leftId.emplace(i);
  std::multiset<std::pair<int, int>> cur;
  std::set<int> curId;
  int ans = 0;
  auto add = [&]() {
    auto it = left.begin();
    if (it == left.end()) return;
    ans -= it->first;
    cur.emplace(-it->first, it->second);
    curId.emplace(it->second);
    leftId.erase(it->second);
    left.erase(it);
  };
  auto sub = [&]() {
    auto it = cur.begin();
    if (it == cur.end()) return;
    ans -= it->first;
    left.emplace(-it->first, it->second);
    leftId.emplace(it->second);
    curId.erase(it->second);
    cur.erase(it);
  };
  for (int i = 0; i < d; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x;
    --y;
    int px = find(x), py = find(y);
    if (px == py) {
      add();
    } else {
      if (curId.count(px)) {
        if (curId.count(py)) {
          add();
        } else {
          leftId.erase(py);
          left.erase({-sz[py], py});
        }
      } else {
        if (curId.count(py)) {
          leftId.erase(px);
          left.erase({-sz[py], px});
        } else {
          left.erase({-sz[px], px});
          left.erase({-sz[py], py});
          sz[px] += sz[py];
          sz[py] = 0;
          p[py] = px;
          leftId.erase(py);
          left.emplace(-sz[px], px);
          add();
        }
      }
      sz[px] += sz[py];
      sz[py] = 0;
      p[py] = px;
    }
    std::cout << ans - 1 << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}