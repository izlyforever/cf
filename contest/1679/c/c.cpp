#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class SegmentTreeAddCountMin {
  int n_;
  std::vector<int> mx;
  void pull(int p) {
    mx[p] = std::min(mx[p << 1], mx[p << 1 | 1]);
  }
  void add(int id, int val, int l, int r, int p) {
    if (r - l == 1) {
      mx[p] += val;
    } else {
      int m = (l + r) / 2;
      if (id < m) add(id, val, l, m, p << 1);
      else add(id, val, m, r, p << 1 | 1);
      pull(p);
    }
  }
  int query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) return mx[p];
    int ans = INT_MAX;
    int m = (l + r) / 2;
    if (L < m) ans = std::min(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::min(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
 public:
  SegmentTreeAddCountMin(int n) : n_(n), mx(n * 4) {}
  void add(int id, int val) { add(id - 1, val, 0, n_, 1); }
  int query(int L, int R) { return query(L - 1, R, 0, n_, 1); }
};

void solve() {
  int n, q;
  std::cin >> n >> q;
  SegmentTreeAddCountMin A(n), B(n);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 3) {
      int x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      int a = A.query(x1, x2);
      int b = B.query(y1, y2);
      std::cout << (a || b ? "Yes" : "No") << '\n';
    } else {
      int p = op == 1 ? 1 : -1;
      int x, y;
      std::cin >> x >> y;
      A.add(x, p);
      B.add(y, p);
    }
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
