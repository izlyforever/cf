#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int query(int l, int r) {
  std::cout << "? " << ++l << ' ' << r << std::endl;
  int x;
  std::cin >> x;
  return x;
}
void out(int x) {
  std::cout << "! " << x << std::endl;
}
class SegTree {
public:
  int n;
  std::vector<int> cnt;
  SegTree(int _n) : n(_n), cnt(4 * n, -1) {}
  int get(int l, int r, int p) {
    if (cnt[p] != -1) return cnt[p];
    return cnt[p] = query(l, r);
  }
  int gets(int k) {
    int l = 0, r = n, p = 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      int t = get(l, m, p << 1);
      if (k <= m - l - t) {
        r = m;
        p <<= 1;
      } else {
        k -= m - l - t;
        l = m;
        p = p << 1 | 1;
      }
    }
    while (p > 1) ++cnt[p], p >>= 1;
    return r;
  }
};

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, t;
  std::cin >> n >> t;
  SegTree A(n);
  while (t--) {
    int k;
    std::cin >> k;
    out(A.gets(k));
  }
  return 0;
}