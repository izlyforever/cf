#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

std::vector<int> nextBig(const std::vector<int>& a) {
  int n = a.size();
  std::vector<int> r(n, n);
  std::stack<int> S;
	for (int i = 0; i < n; ++i) {
		while (!S.empty() && a[S.top()] < a[i]) {
			r[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
  return r;
}

std::vector<int> nextSmall(const std::vector<int>& a) {
  int n = a.size();
  std::vector<int> r(n, n);
  std::stack<int> S;
	for (int i = 0; i < n; ++i) {
		while (!S.empty() && a[S.top()] > a[i]) {
			r[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
  return r;
}

class SegTree {
  int n_;
  std::vector<int> mx, mn;
  void pull(int p) {
    mx[p] = std::max(mx[p << 1], mx[p << 1 | 1]);
    mn[p] = std::min(mn[p << 1], mn[p << 1 | 1]);
  }
  int queryMax(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) return mx[p];
    int ans = 0;
    int m = (l + r) / 2;
    if (L < m) ans = std::max(ans, queryMax(L, R, l, m, p << 1));
    if (R > m) ans = std::max(ans, queryMax(L, R, m, r, p << 1 | 1));
    return ans;
  }
  int queryMin(int L, int R, int l, int r, int p) {
    if (L <= l && R >= r) return mn[p];
    int ans = INT_MAX;
    int m = (l + r) / 2;
    if (L < m) ans = std::min(ans, queryMin(L, R, l, m, p << 1));
    if (R > m) ans = std::min(ans, queryMin(L, R, m, r, p << 1 | 1));
    return ans;
  }
 public:
  SegTree(const std::vector<int>& a) : n_(a.size()), mx(4 * n_), mn(4 * n_) {
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        mx[p] = mn[p] = a[l];
        return;
      }
      int m = (l + r) / 2;
      build(l, m, p << 1);
      build(m, r, p << 1 | 1);
      pull(p);
    };
    build(0, n_, 1);
  }
  int queryMax(int L, int R) { return queryMax(L, R, 0, n_, 1); }
  int queryMin(int L, int R) { return queryMin(L, R, 0, n_, 1); }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), p(n);
  for (auto &x : a) std::cin >> x;
  for (int i = 0; i < n; ++i) p[--a[i]] = i;
  SegTree A(a);
  auto nBig = nextBig(a);
  auto nSmall = nextSmall(a);
  int ans = 0, i = 0;
  while (i < n - 1) {
    ++ans;
    if (a[i + 1] > a[i]) {
      i = p[A.queryMax(i, nSmall[i])];
    } else {
      i = p[A.queryMin(i, nBig[i])];
    }
  }
  std::cout << ans << '\n';
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

