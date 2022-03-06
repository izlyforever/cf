#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class SegmentTree {
  int n_;
  std::vector<int> a_;
  void pull(int p) {
    a_[p] = std::min(a_[p << 1], a_[p << 1 | 1]);
  }
  int query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) return a_[p];
    int ans = INT_MAX;
    int m = (l + r) / 2;
    if (L < m) ans = std::min(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::min(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
 public:
  SegmentTree(std::vector<int> a) : n_(a.size()), a_(4 * n_, INT_MAX) {
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        a_[p] = a[l];
      } else {
        int m = (l + r) / 2;
        build(l, m, p << 1);
        build(m, r, p << 1 | 1);
        pull(p);
      }
    };
    build(0, n_, 1);
  }
  int query(int l, int r) {
    if (l >= r) return 1;
    return query(l, r, 0, n_, 1);
  }
};

struct Node {
  int id, i, c;
  LL s;
  bool operator<(const Node& A) const {
    return s * A.c > c * A.s;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Node> a(n);
  for (int i = 0; i < n; ++i) {
    LL x;
    std::cin >> x;
    a[i] = {i, i, 1, x};
  }
  std::sort(a.begin(), a.end());
  std::vector<std::vector<int>> b(m);
  std::vector<Node> c(m);
  int id = 0;
  for (int i = 0; i < m; ++i) {
    int x;
    std::cin >> x;
    b[i].resize(x);
    for (auto &t : b[i]) std::cin >> t;
    c[i] = {id, i, x, std::accumulate(b[i].begin(), b[i].end(), 0LL)};
    id += x;
  }
  std::vector<int> ans(id);
  std::sort(c.begin(), c.end());
  std::vector<int> norm(m), add(m), sub(m);
  for (int i = 0; i < m; ++i) norm[i] = !(c[i] < a[i]);
  sub[0] = norm[0];
  add.back() = norm.back();
  for (int i = 0; i + 1 < m; ++i) add[i] = !(c[i] < a[i + 1]);
  for (int i = 1; i < m; ++i) sub[i] = !(c[i] < a[i - 1]);
  SegmentTree normT(norm), addT(add), subT(sub);
  for (int i = 0; i < m; ++i) {
    int idx = c[i].i, sx = b[idx].size(), base = c[i].id;
    for (int j = 0; j < sx; ++j) {
      Node x{base + j, idx, sx - 1, c[i].s - b[idx][j]};
      int k = std::lower_bound(c.begin(), c.end(), x) - c.begin();
      if (k > i) {
        ans[x.id] = normT.query(0, i) && normT.query(k, m) && subT.query(i + 1, k) && !(x < a[k - 1]);
      } else {
        ans[x.id] = normT.query(0, k) && normT.query(i + 1, m) && addT.query(k, i) && !(x < a[k]);
      }
    }
  }
  for (auto x : ans) std::cout << x;
  std::cout << '\n';
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
