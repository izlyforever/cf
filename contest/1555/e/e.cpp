#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

class SegTree {
  int n;
  std::vector<int> mx, tag;
  void pushDown(int p) {
    mx[p << 1] += tag[p];
    mx[p << 1 | 1] += tag[p];
    tag[p << 1] += tag[p];
    tag[p << 1 | 1] += tag[p];
    tag[p] = 0;
  }
  void pushUp(int p) {
    mx[p] = std::min(mx[p << 1], mx[p << 1 | 1]);
  }
  void modify(int x, int y, int val, int l, int r, int p) {
    if (x <= l && y >= r) {
      tag[p] += val;
      mx[p] += val;
      return;
    }
    pushDown(p);
    int m = (l + r) / 2;
    if (x < m) modify(x, y, val, l, m, p << 1);
    if (m < y) modify(x, y, val, m, r, p << 1 | 1);
    pushUp(p);
  }
 public:
  SegTree(int _n) : n(_n), mx(n * 4), tag(n * 4) {}
  void modify(int x, int y, int val) {
    modify(--x, y, val, 0, n, 1);
  }
  int max() { return mx[1];}
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  // 可以离散化，但没有必要
  SegTree A(m - 1);
  std::vector<std::tuple<int, int, int>> a(n);
  for (auto& [w, l, r] : a) {
    std::cin >> l >> r >> w;
    --r;
  }
  std::sort(a.begin(), a.end());
  int ans = INT_MAX;
  for (int l = 0, r = 0; r < n; ++r) {
    A.modify(std::get<1>(a[r]), std::get<2>(a[r]), 1);
    while (A.max()) {
      ans = std::min(ans, std::get<0>(a[r]) - std::get<0>(a[l]));
      A.modify(std::get<1>(a[l]), std::get<2>(a[l]), -1);
      ++l;
    }
  }
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
