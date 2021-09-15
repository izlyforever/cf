#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

class SegmentTree {
  int n;
  std::vector<int> mn;
  void pull(int p) {
    mn[p] = std::min(mn[p << 1], mn[p << 1 | 1]);
  }
  int query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) return mn[p];
    int ans = INT_MAX;
    int m = (l + r) / 2;
    if (L < m) ans = std::min(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::min(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
  int queryIndex(int L, int R, int l, int r, int p) {
    if (r - l == 1) return l;
    int lmn = INT_MAX, rmn = INT_MAX;
    int m = (l + r) / 2;
    if (L < m) lmn = query(L, R, l, m, p << 1);
    if (R > m) rmn = query(L, R, m, r, p << 1 | 1);
    if (lmn <= rmn) return queryIndex(L, R, l, m, p << 1);
    return queryIndex(L, R, m, r, p << 1 | 1);
  }
 public:
  SegmentTree(const std::vector<int>& a) : n(a.size()), mn(4 * n) {
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        mn[p] = a[l];
        return;
      }
      int m = (l + r) / 2;
      build(l, m, p << 1);
      build(m, r, p << 1 | 1);
      pull(p);
    };
    build(0, n, 1);
  }
  int query(int L, int R) {
    return queryIndex(L, R, 0, n, 1);
  }
};

LL solve() {
  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  SegmentTree A(a);
  LL ans = 0;
  std::function<void(int, int)> dfs = [&](int L, int R) {
    if (R - L <= 1) return;
    int m = A.query(L, R), l = m, r = m;
    if (a[m] >= c) {
      ans += LL(R - L - 1) * c;
      return;
    }
    while (l >= L && a[l] % a[m] == 0) --l;
    ++l;
    while (r < R && a[r] % a[m] == 0) ++r;
    if (L < l) {
      if (l == m) {
        ans += c;
        dfs(L, l);
      } else dfs(L, l + 1);
    }
    if (r < R) {
      if (r - 1 == m) {
        ans += c;
        dfs(r, R);
      } else dfs(r - 1, R);
    }
    ans += LL(r - l - 1) * a[m];
  };
  dfs(0, a.size());
  return ans;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}