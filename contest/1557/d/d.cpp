#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// make sure that a[i].first <= a[i].second
void disjointInterval(std::vector<std::pair<int, int>>& a) {
  if (a.size() <= 1) return;
  std::vector<std::pair<int, int>> b;
  std::sort(a.begin(), a.end());
  int l = a[0].first, r = a[0].second;
  for (int i = 1, n = a.size(); i < n; ++i) {
    if (a[i].first <= r) {
      r = std::max(r, a[i].second);
    } else {
      b.emplace_back(l, r);
      l = a[i].first, r = a[i].second;
    }
  }
  b.emplace_back(l, r);
  std::swap(a, b);
}

using Node = std::pair<int, int>;
class SegTree {
  std::vector<Node> mx, tag;
  int n;
  void pushDown(int p) {
    if (tag[p] == pt) return;
    tag[p << 1] = mx[p << 1] = tag[p];
    tag[p << 1 | 1] = mx[p << 1 | 1] = tag[p];
    tag[p] = pt;
  }
  void pushUp(int p) {
    mx[p] = std::max(mx[p << 1], mx[p << 1 | 1]);
  }
  void modify(int L, int R, const Node& x, int l, int r, int p) {
    if (L <= l && r <= R) {
      tag[p] = mx[p] = x;
      return;
    }
    int m = (l + r) / 2;
    pushDown(p);
    if (L < m) modify(L, R, x, l, m, p << 1);
    if (R > m) modify(L, R, x, m, r, p << 1 | 1);
    pushUp(p);
  }
  Node query(int L, int R, int l, int r, int p) {
    if (L <= l && r <= R) {
      return mx[p];
    }
    int m = (l + r) / 2;
    pushDown(p);
    auto ans = pt;
    if (L < m) ans = std::max(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::max(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
 public:
  static inline const Node pt{0, -1};
  SegTree(int _n) : n(_n), mx(4 * _n, pt), tag(4 * _n, pt) {}
  Node query(int L, int R) {
    return query(L, ++R, 0, n, 1);
  }
  void modify(int L, int R, const Node& x) {
    modify(L, ++R, x, 0, n, 1);
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> a(n);
  for (int i = 0; i < m; ++i) {
    int id, l, r;
    std::cin >> id >> l >> r;
    a[--id].emplace_back(l, r);
  }
  for (int i = 0; i < n; ++i) disjointInterval(a[i]);
  std::vector<int> tmp;
  for (auto& x : a) {
    for (auto [l, r] : x) {
      tmp.emplace_back(l);
      tmp.emplace_back(r);
    }
  }
  std::sort(tmp.begin(), tmp.end());
  tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
  for (auto& x : a) {
    for (auto& [l, r] : x) {
      l = std::lower_bound(tmp.begin(), tmp.end(), l) - tmp.begin();
      r = std::lower_bound(tmp.begin(), tmp.end(), r) - tmp.begin();
    }
  }
  int sz = tmp.size();
  SegTree A(sz);
  std::vector<Node> p(n);
  for (int i = 0; i < n; ++i) {
    Node mx{-1, INT_MAX};
    for (auto [l, r] : a[i]) {
      mx = std::max(mx, A.query(l, r));
    }
    ++mx.first;
    p[i] = mx;
    mx.second = i;
    for (auto [l, r] : a[i]) {
      A.modify(l, r, mx);
    }
  }
  auto now = std::max_element(p.begin(), p.end()) - p.begin();
  std::vector<int> cnt(n), ans;
  while (now != -1) {
    cnt[now] = 1;
    now = p[now].second;
  }
  for (int i = 0; i < n; ++i) if (!cnt[i]) ans.emplace_back(i + 1);
  std::cout << ans.size() << '\n';
  for (auto x : ans) std::cout << x << ' ';
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
