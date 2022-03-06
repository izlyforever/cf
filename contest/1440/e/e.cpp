#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

struct SegmentTree {
  int n;
  std::vector<int> mn, tag;
  std::vector<LL> sm;
  #define lson l, m, 2 * p
  #define rson m + 1, r, 2 * p + 1
  void resize() {
    mn.resize(4 * n);
    tag.resize(4 * n);
    sm.resize(4 * n);
  }
  SegmentTree(int _n) : n(_n) {
    resize();
  }
  SegmentTree(const std::vector<int>& a) {
    n = a.size();
    resize();
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (l == r) {
        mn[p] = sm[p] = a[l - 1];
        return;
      }
      int m = (l + r) / 2;
      build(lson);
      build(rson);
      pull(p);
    };
    build(1, n, 1);
  }
  void pull(int p) {
    mn[p] = std::min(mn[2 * p], mn[2 * p + 1]);
    sm[p] = sm[2 * p] + sm[2 * p + 1];
  }
  void push(int l, int r, int p) {
    if (tag[p]) {
      int m = (l + r) / 2;
      set(lson, tag[p]);
      set(rson, tag[p]);
      tag[p] = 0;
    }
  }
  void set(int l, int r, int p, int v) {
    tag[p] = mn[p] = v;
    sm[p] = LL(r - l + 1) * v;
  }
  void rangeSet(int L, int R, int v, int l, int r, int p) {
    if (L <= l && R >= r) {
      set(l, r, p, v);
      return;
    }
    int m = (l + r) / 2;
    push(l, r, p);
    if (L <= m) rangeSet(L, R, v, lson);
    if (R > m) rangeSet(L, R, v, rson);
    pull(p);
  }
  // 以下内容根据需要修改
  int query(int x, int& y, int l, int r, int p) {
    if (mn[p] > y) return 0;
    if (x <= l && sm[p] <= y) {
      y -= sm[p];
      return r - l + 1;
    }
    int m = (l + r) / 2;
    push(l, r, p);
    int ans = 0;
    if (x <= m) ans += query(x, y, lson);
    ans += query(x, y, rson);
    return ans;
  }
  int bounded(int v, int l, int r, int p) {
    if (mn[p] >= v) return r + 1;
    if (l == r) return l;
    int m = (l + r) / 2;
    if (mn[2 * p] >= v) return bounded(v, rson);
    return bounded(v, lson);
  }
  void modify(int x, int y) {
    int l = bounded(y, 1, n, 1);
    if (l <= x) rangeSet(l, x, y, 1, n, 1);
  }
  int query(int x, int y) {
    return query(x, y, 1, n, 1);
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (auto& x: a) std::cin >> x;
  SegmentTree A(a);
  while (q--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) A.modify(x, y);
    else std::cout << A.query(x, y) << std::endl;
  }
  return 0;
}
