#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class Seg {
  int n_;
  std::vector<int> mx;
  int query(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) {
      return mx[p];
    }
    int m = (l + r) / 2;
    int ans = INT_MIN;
    if (L < m) ans = std::max(ans, query(L, R, l, m, p << 1));
    if (R > m) ans = std::max(ans, query(L, R, m, r, p << 1 | 1));
    return ans;
  }
 public:
  Seg(const std::vector<int>& a) : n_(a.size()), mx(4 * n_) {
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        mx[p] = a[l];
      } else {
        int m = (l + r) / 2;
        build(l, m, p << 1);
        build(m, r, p << 1 | 1);
        mx[p] = std::max(mx[p << 1], mx[p << 1 | 1]);
      }
    };
    build(0, n_, 1);
  }
  int query(int L, int R) {
    return query(L - 1, R, 0, n_, 1);
  }
};

void solve() {
  int n, m;
  std::cin >> m >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  Seg A(a);
  auto check = [&](int x1, int y1, int x2, int y2, int k) -> bool {
    if (y1 > y2) {
      std::swap(x1, x2);
      std::swap(y1, y2);
    }
    if ((x2 - x1) % k) return false;
    if ((y2 - y1) % k) return false;
    return A.query(y1, y2) < (m - x1) / k * k + x1;
  };
  int q;
  std::cin >> q;
  while (q--) {
    int x1, y1, x2, y2, k;
    std::cin >> x1 >> y1 >> x2 >> y2 >> k;
    std::cout << (check(x1, y1, x2, y2, k) ? "YES" : "NO") << '\n';
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
