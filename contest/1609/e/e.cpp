#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<class Info>
class SegmentTree {
  int n_;
  std::vector<Info> info_;
  void pull(int p) {
    info_[p] = info_[p << 1] + info_[p << 1 | 1];
  }
  void modify(const Info& v, int x, int l, int r, int p) {
    if (r - l == 1) {
      info_[p] = v;
    } else {
      int m = (l + r) / 2;
      if (x < m) modify(v, x, l, m, p << 1);
      else modify(v, x, m, r, p << 1 | 1);
      pull(p);
    }
  }
 public:
  SegmentTree(int n) : n_(n), info_(4 << std::__lg(n)) {}
  SegmentTree(const std::vector<Info>& a) : SegmentTree(a.size()) {
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        info_[p] = a[l];
      } else {
        int m = (l + r) / 2;
        build(l, m, p << 1);
        build(m, r, p << 1 | 1);
        pull(p);
      }
    };
    build(0, n_, 1);
  }
  void modify(const Info& v, int x) {
    modify(v, x, 0, n_, 1);
  }
  int getAns() {
    return info_[1].getAns();
  }
};

struct Info {
  int f[3][3];
  void all(int x) {
    for (int i = 0; i < 3; ++i) {
      for (int j = i; j < 3; ++j) {
        f[i][j] = x;
      }
    }
  }
  Info() {
    all(0);
  }
  Info(int x) : Info() {
    ++f[x][x];
  }
  friend Info operator+(const Info& A, const Info& B) {
    Info C;
    C.all(1e9);
    for (int i = 0; i < 3; ++i) {
      for (int j = i; j < 3; ++j) {
        for (int k = j; k < 3; ++k) {
          C.f[i][k] = std::min(C.f[i][k], A.f[i][j] + B.f[j][k]);
        }
      }
    }
    return C;
  }
  int getAns() const {
    return std::min({f[0][0], f[0][1], f[0][2], f[1][1], f[1][2], f[2][2]});
  }
};

void solve() {
  int n, q;
  std::string s;
  std::cin >> n >> q >> s;
  std::vector<Info> a(n);
  for (int i = 0; i < n; ++i) a[i] = Info(s[i] - 'a');
  SegmentTree A(a);
  while (q--) {
    int x;
    char c;
    std::cin >> x >> c;
    A.modify(Info(c - 'a'), --x);
    std::cout << A.getAns() << '\n';
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
