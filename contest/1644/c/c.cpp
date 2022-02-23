#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class SegmentTree {
  int n_;
  std::vector<int> mx, tag;
  void pull(int p) { mx[p] = std::max(mx[p << 1], mx[p << 1 | 1]); }
  void pushTag(int x, int l, int r, int p) {
    tag[p] += x;
    mx[p] += x;
  }
  void push(int l, int r, int p) {
    if (tag[p]) {
      int m = (l + r) / 2;
      pushTag(tag[p], l, m, p << 1);
      pushTag(tag[p], m, r, p << 1 | 1);
      tag[p] = 0;
    }
  }
  void rangeAdd(int L, int R, int x, int l, int r, int p) {
    if (L <= l && R >= r) {
      pushTag(x, l, r, p);
      return;
    }
    push(l, r, p);
    int m = (l + r) / 2;
    if (L < m) rangeAdd(L, R, x, l, m, p << 1);
    if (R > m) rangeAdd(L, R, x, m, r, p << 1 | 1);
    pull(p);
  }
  // you should implement it to meet for needs
  int query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) return mx[p];
    push(l, r, p);
    int ans = 0;
    int m = (l + r) / 2;
    if (L < m) ans = std::max(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::max(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
  void resize() {
    tag.resize(4 * n_);
    mx.resize(4 * n_);
  }
 public:
  SegmentTree(int n) : n_(n) { resize(); }
  SegmentTree(const std::vector<int>& a) {
    n_ = (int)a.size();
    resize();
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        mx[p] = a[l];
        return;
      }
      int m = (l + r) / 2;
      build(l, m, p << 1);
      build(m, r, p << 1 | 1);
      pull(p);
    };
    build(0, n_, 1);
  }
  void add(int L, int R, int v) { rangeAdd(L, R, v, 0, n_, 1); }
  int query(int L, int R) { return query(L, R, 0, n_, 1); }
};

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<int> ans(n + 1);
  for (int i = 0; i < n; ++i) {
    std::vector<int> c(n - i);
    for (int j = 0, now = 0; i + j < n; ++j) {
      now += a[i + j];
      c[j] = now;
    }
    SegmentTree A(c);
    for (int j = 0; j < n - i; ++j) {
      ans[j] = std::max(ans[j], A.query(0, n - i));
      A.add(j, n - i, x);
    }
    ans[n - i] = std::max(ans[n - i], A.query(0, n - i));
  }
  for (int i = 1; i <= n; ++i) ans[i] = std::max(ans[i], ans[i - 1]);
  for (int i = 0; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
