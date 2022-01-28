#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class SegmentTree {
  int n_;
  std::vector<int> mx;
  void pull(int p) {
    mx[p] = std::max(mx[p << 1], mx[p << 1 | 1]);
  }
  int query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) return mx[p];
    int ans = INT_MIN;
    int m = (l + r) / 2;
    if (L < m) ans = std::max(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::max(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
  void modify(int pos, int val, int l, int r, int p) {
    if (r - l == 1) {
      mx[p] = val;
    } else {
      int m = (l + r) / 2;
      if (pos < m) modify(pos, val, l, m, p << 1);
      else modify(pos, val, m, r, p << 1 | 1);
      pull(p);
    }
  }
 public:
  SegmentTree(int n) : n_(n), mx(4 * n_, INT_MIN) {}
  void modify(int x, int v) { modify(x, v, 0, n_, 1); }
  int query(int L, int R) { return query(L, R, 0, n_, 1);}
};


void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), l(n + 1);
  for (auto &x : a) std::cin >> x;
  for (int i = n - 1; i >= 0; --i) {
    l[a[i]] = i;
  }
  SegmentTree A(n);
  A.modify(0, 0);
  std::vector<int> dp(n);
  for (int i = 1; i < n; ++i) {
    dp[i] = dp[i - 1];
    if (l[a[i]] != i) {
      dp[i] = std::max(dp[i], A.query(l[a[i]], i) + i - 1);
    }
    A.modify(i, dp[i] - i);
  }
  std::cout << dp.back() << '\n';
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