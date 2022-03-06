#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class ModInt {
  static inline int M = 998244353;
  int n_;
// |x| <= max(1, b), |y| <= a ===> |y - a / b * x| <= a % b + a / b * b = a
  static std::tuple<int, int, int> exGcdInternal(int a, int b) {
    if (b == 0) return {a, 1, 0};
    auto [d, y, x] = exGcdInternal(b, a % b);
    return {d, x, y - a / b * x};
  }
  static int inv(int a) {
    auto [d, x, y] = exGcdInternal(a, M);
    // assert(d == 1);
    return x < 0 ? x + M : x;
  }
  // assum M is prime
  static int invP(int x) {
    return x == 1 ? x : 1LL * (M - M / x) * invP(M % x) % M;
  }
 public:
  template<typename T>
   operator T() const {
    return static_cast<T>(n_);
  }
  static void setMod(int m) {
    assert(M == m);
  }
  static int mod() {
    return M;
  }
  // assume 0 <= x < M
  static ModInt raw(int x) {
    ModInt A;
    A.n_ = x;
    return A;
  }
  ModInt() { n_ = 0;}
  ModInt(const int& x) : n_(x % M) {
    if (n_ < 0) n_ += M;
  }
  ModInt(const LL& x) : n_(x % M) {
    if (n_ < 0) n_ += M;
  }
  ModInt operator-() const {
    return n_ == 0 ? *this : raw(M - n_);
  }
  ModInt& operator++() {
    if (++n_ == M) n_ = 0;
    return *this;
  }
  ModInt& operator--() {
    if (n_-- == 0) n_ += M;
    return *this;
  }
  ModInt& operator+=(const ModInt& A) {
    n_ += A.n_;
    if (n_ >= M) n_ -= M;
    return (*this);
  }
  ModInt& operator-=(const ModInt& A) {
    n_ -= A.n_;
    if (n_ < 0) n_ += M;
    return (*this);
  }
  ModInt& operator*=(const ModInt& A) {
    n_ = 1LL * n_ * A.n_ % M;
    return (*this);
  }
  ModInt& operator/=(const ModInt& A) {
    return (*this) *= A.inv();
  }
  ModInt operator+(const ModInt& A) const {
    return ModInt(*this) += A;
  }
  ModInt operator-(const ModInt& A) const {
    return ModInt(*this) -= A;
  }
  ModInt operator*(const ModInt& A) const {
    return ModInt(*this) *= A;
  }
  ModInt operator/(const ModInt& A) const {
    return ModInt(*this) /= A;
  }
  ModInt operator<<(int x) const {
    static constexpr int bits = 32;
    LL r = n_;
    while (x > bits) {
      x -= bits;
      r <<= bits;
      r %= M;
    }
    r <<= x;
    return ModInt(r);
  }
  ModInt& operator<<=(int x) {
    return (*this) = (*this) << x;
  }
  bool operator==(const ModInt& A) const {
    return n_ == A.n_;
  }
  bool operator!=(const ModInt& A) const {
    return n_ != A.n_;
  }
  ModInt inv() const {
    return inv(n_);
  }
  ModInt invP() const {
    return invP(n_);
  }
  friend ModInt pow(ModInt A, int n) {
    ModInt R(1);
    while (n) {
      if (n & 1) R *= A;
      n >>= 1;   A *= A;
    }
    return R;
  }
  friend std::istream& operator>>(std::istream& in, ModInt& A) {
    LL x;
    in >> x;
    A = ModInt(x);
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const ModInt& A) {
    out << A.n_;
    return out;
  }
};

template<typename T>
struct Bitree {
  std::vector<T> s_;
  Bitree() {}
  Bitree(int n) : s_(n + 1) {}
  // https://codeforces.com/blog/entry/59305
  Bitree(const std::vector<T>& a) : s_(a.size() + 1) {
    int n = a.size();
    for (int i = 0; i < n; ++i) s_[i + 1] = s_[i] + a[i];
    for (int i = n; i > 0; --i) s_[i] -= s_[i - lowbit(i)];
  }
  std::vector<T> getOrigin() const {
    auto a = s_;
    int n = s_.size() - 1;
    for (int i = 1; i <= n; ++i) a[i] += a[i - lowbit(i)];
    std::vector<T> ans(n);
    for (int i = n - 1; i >= 0; --i) ans[i] = a[i + 1] - a[i];
    return ans;
  }
  static int lowbit(int n) { return n & (-n); }
  void add(int id, T p) {
    int ns = s_.size();
    while (id < ns) {
      s_[id] += p;
      id += lowbit(id);
    }
  }
  T sum(int id) {
    T r = 0;
    while (id) {
      r += s_[id];
      id -= lowbit(id);
    }
    return r;
  }
  T sum(int l, int r) { return sum(r) - sum(l - 1); }
};
const int N = 1e6 + 2;
std::vector<ModInt> fac(N), ifac(N);
void init() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * ModInt::raw(i);
  ifac[N - 1] = fac[N - 1].inv();
  for (int i = N - 1; i > 0; --i) ifac[i - 1] = ifac[i] * ModInt::raw(i);
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> s(N);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++s[x];
  }
  Bitree<ModInt> A(N);
  for (int i = 1; i < N; ++i) A.add(i, s[i]);

  std::vector<int> t(m);
  for (auto &x : t) std::cin >> x;
  ModInt ans{0};
  ModInt rate = 1;
  for (auto &x : s) rate *= ifac[x];
  for (int i = 0; i < m; ++i) {
    if (i == n) {
      ans += 1;
      break;
    }
    int x = t[i];
    ans += A.sum(x - 1) * fac[n - i - 1] * rate;
    if (s[x] == 0) {
      break;
    }
    rate *= s[x]--;
    A.add(x, -1);
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  init();
  while (cas--) {
    solve();
  }
  return 0;
}