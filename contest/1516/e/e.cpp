#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 1e9 + 7;
LL powModLL(LL x, LL n) {
  LL r(1);
  while (n) {
    if (n & 1) r = r * x % M;
    n >>= 1; x = x * x % M;
  }
  return r;
}
class Poly {
  void standard() {
    while (!a.empty() && !a.back()) a.pop_back();
  }
  void reverse() {
    std::reverse(a.begin(), a.end());
    standard();
  }
 public:
  std::vector<LL> a;
  Poly() {}
  Poly(LL x) { if (x) a = {x};}
  Poly(const std::vector<LL> _a) : a(_a) { standard();}
  int size() const { return a.size();}
  LL operator[](int id) const {
    if (id < 0 || id > a.size()) return 0;
    return a[id];
  }
  Poly mulXn(int n) const {
    auto b = a;
    b.insert(b.begin(), n, 0);
    return Poly(b);
  }
  Poly modXn(int n) const {
    if (n > size()) return *this;
    return Poly(std::vector<LL>(a.begin(), a.begin() + n));
  }
  Poly divXn(int n) const {
    if (size() <= n) return Poly();
    return Poly(std::vector<LL>(a.begin() + n, a.end()));
  }
  Poly& operator+=(const Poly& A) {
    if (size() < A.size()) a.resize(A.size());
    for (int i = 0; i < A.size(); ++i) {
      if ((a[i] += A.a[i]) >= M) a[i] -= M;
    }
    standard();
    return *this;
  }
  Poly& operator-=(const Poly& rhs) {
    if (size() < rhs.size()) a.resize(rhs.size());
    for (int i = 0; i < rhs.size(); ++i) {
      if ((a[i] -= rhs.a[i]) < 0) a[i] += M;
    }
    standard();
    return *this;
  }
  Poly& operator*=(Poly rhs) {
    return *this = (*this * rhs);
  }
  Poly& operator/=(Poly rhs) {
    int n = size(), m = rhs.size();
    if (n < m) return (*this) = Poly();
    reverse();
    rhs.reverse();
    (*this) *= rhs.inv(n - m + 1);
    a.resize(n - m + 1);
    reverse();
    return *this;
  }
  Poly& operator%=(Poly rhs) {
    return (*this) -= (*this) / rhs * rhs;
  }
  Poly operator+(const Poly& rhs) const {
    return Poly(*this) += rhs;
  }
  Poly operator-(const Poly& rhs) const {
    return Poly(*this) -= rhs;
  }
  Poly operator*(Poly rhs) const {
    std::vector<LL> r(size() + rhs.size() - 1);
    for (int i = 0; i < size(); ++i) {
      for (int j = 0; j < rhs.size(); ++j) {
        (r[i + j] += a[i] * rhs.a[j]) %= M;
      }
    }
    return Poly(r);
  }
  Poly operator/(Poly rhs) const {
    return Poly(*this) /= rhs;
  }
  Poly operator%(Poly rhs) const {
    return Poly(*this) %= rhs;
  }
  Poly powMod(int n, Poly p) {
    Poly r(1), x(*this);
    while (n) {
      if (n & 1) (r *= x) %= p;
      n >>= 1;   (x *= x) %= p;
    }
    return r;
  }
  LL inner(const Poly & rhs) {
    LL r = 0;
    int n = std::min(size(), rhs.size());
    for (int i = 0; i < n; ++i) {
      r = (r + a[i] * rhs.a[i]) % M;
    }
    return r;
  }
  Poly derivation() const {
    if (a.empty()) return Poly();
    int n = size();
    std::vector<LL> r(n - 1);
    for (int i = 1; i < n; ++i) r[i - 1] =  a[i] * i % M;
    return Poly(r);
  }
  Poly integral() const {
    if (a.empty()) return Poly();
    int n = size();
    std::vector<LL> r(n + 1), inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = (M - M / i) * inv[M % i] % M;
    for (int i = 0; i < n; ++i) r[i + 1] = a[i] * inv[i + 1] % M;
    return Poly(r);
  }
  Poly inv(int n) const {
    assert(a[0] != 0);
    Poly x(powModLL(a[0], M - 2));
    int k = 1;
    while (k < n) {
      k *= 2;
      x *= (Poly(2) - modXn(k) * x).modXn(k);
    }
    return x.modXn(n);
  }
  // 需要保证首项为 1
  Poly log(int n) const {
    return (derivation() * inv(n)).integral().modXn(n);
  }
  // 需要保证首项为 0
  Poly exp(int n) const {
    Poly x(1);
    int k = 1;
    while (k < n) {
      k *= 2;
      x = (x * (Poly(1) - x.log(k) + modXn(k))).modXn(k);
    }
    return x.modXn(n);
  }
  // 需要保证首项为 1，开任意次方可以先 ln 再 exp 实现。
  Poly sqrt(int n) const {
    Poly x(1);
    int k = 1;
    LL inv2 = (M + 1) / 2;
    while (k < n) {
      k *= 2;
      x += modXn(k) * x.inv(k);
      x = x.modXn(k) * inv2;
    }
    return x.modXn(n);
  }
  // 减法卷积，也称转置卷积 {\rm MULT}(F(x),G(x))=\sum_{i\ge0}(\sum_{j\ge 0}f_{i+j}g_j)x^i
  Poly mulT(Poly rhs) const {
    if (rhs.size() == 0) return Poly();
    int n = rhs.size();
    std::reverse(rhs.a.begin(), rhs.a.end());
    return ((*this) * rhs).divXn(n - 1);
  }
  LL eval(LL x) {
    x %= M;
    LL r = 0, t = 1;
    for (int i = 0, n = size(); i < n; ++i) {
      r = (r + a[i] * t) % M;
      t = t * x % M;
    }
    return r;
  }
  // 多点求值新科技：https://jkloverdcoi.github.io/2020/08/04/转置原理及其应用/
  std::vector<LL> eval(std::vector<LL> x) const {
    if (size() == 0) return std::vector<LL>(x.size());
    int n = x.size();
    std::vector<LL> ans(n);
    std::vector<Poly> g(4 * n);
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        g[p] = std::vector<LL>{1, (M - x[l]) % M};
      } else {
        int m = (l + r) / 2;
        build(l, m, 2 * p);
        build(m, r, 2 * p + 1);
        g[p] = g[2 * p] * g[2 * p + 1];
      }
    };
    build(0, n, 1);
    std::function<void(int, int, int, const Poly& )> solve = [&](int l, int r, int p, const Poly& f) {
      if (r - l == 1) {
        ans[l] = f[0];
      } else {
        int m = (l + r) / 2;
        solve(l, m, 2 * p, f.mulT(g[2 * p + 1]).modXn(m - l));
        solve(m, r, 2 * p + 1, f.mulT(g[2 * p]).modXn(r - m));
      }
    };
    solve(0, n, 1, mulT(g[1].inv(size())).modXn(n));
    return ans;
  } // 模板例题：https://www.luogu.com.cn/problem/P5050
}; // Poly 全家桶测试：https://www.luogu.com.cn/training/3015#information

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  Poly Numerator = Poly(std::vector<LL>{0, n}).exp(k + 2).divXn(1);
  Poly denominator  = Poly(std::vector<LL>{0, 1}).exp(k + 2).divXn(1);
  auto f = (Numerator * denominator.inv(k + 1)).modXn(k + 1).a;
  f.resize(k + 1);
  std::vector<LL> g(k + 1);
  LL now = 1;
  for (int i = 1; i <= k; ++i) {
    g[i] = f[i] * (i & 1 ? now : M - now) % M;
    if (i > 1) now = now * i % M;
  }
  auto ans = Poly(g).exp(k + 1).a;
  ans.resize(k + 1);
  LL s[2]{1, 0};
  for (int i = 1; i <= k; ++i) {
    if ((s[i & 1] += ans[i]) >= M) s[i & 1] -= M;
    std::cout << s[i & 1] << ' ';
  }
  std::cout << '\n';
  return 0;
}