#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

template <int N>
class MInt {
  static inline constexpr int M = N;
  int n;
  static int inv(int x) {
    // assert(std::gcd(x, M) == 1);
    return x == 1 ? x : 1LL * (M - M / x) * inv(M % x) % M;
  }

 public:
  static void setMod(int m) { M = m; }
  static constexpr int mod() { return M; }
  // 请自行确保 0 <= x < M
  static MInt raw(int x) {
    MInt A;
    A.n = x;
    return A;
  }
  MInt(LL x = 0) : n(x % M) {
    if (n < 0) n += M;
  }
  operator int() const { return n; }
  MInt operator-() const { return n == 0 ? *this : raw(M - n); }
  MInt& operator++() {
    if (++n == M) n = 0;
    return *this;
  }
  MInt& operator--() {
    if (--n == -1) n += M;
    return *this;
  }
  MInt& operator+=(const MInt& A) {
    n += A.n;
    if (n >= M) n -= M;
    return (*this);
  }
  MInt& operator-=(const MInt& A) {
    n -= A.n;
    if (n < 0) n += M;
    return (*this);
  }
  MInt& operator*=(const MInt& A) {
    n = 1LL * n * A.n % M;
    return (*this);
  }
  MInt& operator/=(const MInt& A) { return (*this) *= A.inv(); }
  MInt operator+(const MInt& A) const { return MInt(*this) += A; }
  MInt operator-(const MInt& A) const { return MInt(*this) -= A; }
  MInt operator*(const MInt& A) const { return MInt(*this) *= A; }
  MInt operator/(const MInt& A) const { return MInt(*this) /= A; }
  MInt operator<<(int x) const {
    LL r = n;
    r <<= x;
    return MInt(r);
  }
  MInt& operator<<=(int x) { return (*this) = (*this) << x; }
  MInt& operator>>=(int x) {
    n >>= x;
    return (*this);
  }
  MInt operator>>(int x) const { return MInt(*this) >> x; }
  MInt operator&(int x) const { return MInt(*this) & x; }
  MInt& operator &=(int x) {
    n &= x;
    return (*this);
  }
  MInt inv() const { return inv(n); }
  friend MInt pow(MInt A, int n) {
    MInt R(1);
    while (n) {
      if (n & 1) R *= A;
      n >>= 1;
      A *= A;
    }
    return R;
  }
  friend std::istream& operator>>(std::istream& in, MInt& A) {
    LL x;
    in >> x;
    A = MInt(x);
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const MInt& A) {
    out << A.n;
    return out;
  }
};

class ModInt {
  static inline int M = 998244353;
  int n;
  static int inv(int x) {
    // assert(std::gcd(x, M) == 1);
    return x == 1 ? x : 1LL * (M - M / x) * inv(M % x) % M;
  }

 public:
  static void setMod(int m) { M = m; }
  static int mod() { return M; }
  // 自行确保 0 <= x < M
  static ModInt raw(int x) {
    ModInt A;
    A.n = x;
    return A;
  }
  ModInt(LL x = 0) : n(x % M) {
    if (n < 0) n += M;
  }
  ModInt operator-() const { return n == 0 ? *this : raw(M - n); }
  ModInt& operator++() {
    if (++n == M) n = 0;
    return *this;
  }
  ModInt& operator--() {
    if (--n == -1) n += M;
    return *this;
  }
  operator int() const { return n; }
  ModInt& operator+=(const ModInt& A) {
    n += A.n;
    if (n >= M) n -= M;
    return (*this);
  }
  ModInt& operator-=(const ModInt& A) {
    n -= A.n;
    if (n < 0) n += M;
    return (*this);
  }
  ModInt& operator*=(const ModInt& A) {
    n = 1LL * n * A.n % M;
    return (*this);
  }
  ModInt& operator/=(const ModInt& A) { return (*this) *= A.inv(); }
  ModInt operator+(const ModInt& A) const { return ModInt(*this) += A; }
  ModInt operator-(const ModInt& A) const { return ModInt(*this) -= A; }
  ModInt operator*(const ModInt& A) const { return ModInt(*this) *= A; }
  ModInt operator/(const ModInt& A) const { return ModInt(*this) /= A; }
  ModInt operator<<(int x) const {
    LL r = n;
    r <<= x;
    return ModInt(r);
  }
  ModInt& operator<<=(int x) { return (*this) = (*this) << x; }
  ModInt& operator>>=(int x) {
    n >>= x;
    return (*this);
  }
  ModInt operator>>(int x) const { return ModInt(*this) >> x; }
  ModInt operator&(int x) const { return ModInt(*this) & x; }
  ModInt& operator &=(int x) {
    n &= x;
    return (*this);
  }
  ModInt inv() const { return inv(n); }
  friend ModInt pow(ModInt A, int n) {
    ModInt R(1);
    while (n) {
      if (n & 1) R *= A;
      n >>= 1;
      A *= A;
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
    out << A.n;
    return out;
  }
};

class ModLL {
  static inline LL M = 998244353;
  LL n;
  static LL inv(LL x) {
    // assert(std::gcd(x, M) == 1);
    return x == 1 ? x : __int128(M - M / x) * inv(M % x) % M;
  }

 public:
  static void setMod(LL m) { M = m; }
  static LL mod() { return M; }
  // 自行确保 0 <= x < M
  static ModLL raw(LL x) {
    ModLL A;
    A.n = x;
    return A;
  }
  ModLL(__int128 x = 0) : n(x % M) {
    if (n < 0) n += M;
  }
  ModLL operator-() const { return n == 0 ? *this : raw(M - n); }
  ModLL& operator++() {
    if (++n == M) n = 0;
    return *this;
  }
  ModLL& operator--() {
    if (--n == -1) n += M;
    return *this;
  }
  operator LL() const { return n; }
  ModLL& operator+=(const ModLL& A) {
    n += A.n;
    if (n >= M) n -= M;
    return (*this);
  }
  ModLL& operator-=(const ModLL& A) {
    n -= A.n;
    if (n < 0) n += M;
    return (*this);
  }
  ModLL& operator*=(const ModLL& A) {
    n = __int128(n) * A.n % M;
    return (*this);
  }
  ModLL& operator/=(const ModLL& A) { return (*this) *= A.inv(); }
  ModLL operator+(const ModLL& A) const { return ModLL(*this) += A; }
  ModLL operator-(const ModLL& A) const { return ModLL(*this) -= A; }
  ModLL operator*(const ModLL& A) const { return ModLL(*this) *= A; }
  ModLL operator/(const ModLL& A) const { return ModLL(*this) /= A; }
  ModLL operator<<(int x) const {
    __int128 r = n;
    r <<= x;
    return ModLL(r);
  }
  ModLL& operator<<=(int x) { return (*this) = (*this) << x; }
  ModLL& operator>>=(int x) {
    n >>= x;
    return (*this);
  }
  ModLL operator>>(int x) const { return ModLL(*this) >> x; }
  ModLL operator&(int x) const { return ModLL(*this) & x; }
  ModLL& operator &=(LL x) {
    n &= x;
    return (*this);
  }
  ModLL inv() const { return inv(n); }
  friend ModLL pow(ModLL A, LL n) {
    ModLL R(1);
    while (n) {
      if (n & 1) R *= A;
      n >>= 1;
      A *= A;
    }
    return R;
  }
  friend std::istream& operator>>(std::istream& in, ModLL& A) {
    LL x;
    in >> x;
    A = ModLL(x);
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const ModLL& A) {
    out << A.n;
    return out;
  }
};

// 为了支持三模数，改成模板类的形式
template <int M>
class NTT {   // 请自行保证输入的 N 为 原根 3 的 NTT-friendly 素数
  std::vector<int> rev;
  std::vector<MInt<M>> roots{0, 1};

 public:
  static inline const MInt<M> g = 3;
  void dft(std::vector<MInt<M>>& a) {
    int n = a.size();
    if ((int)rev.size() != n) {
      int k = __builtin_ctz(n) - 1;
      rev.resize(n);
      for (int i = 0; i < n; ++i) {
        rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
      }
    }
    if ((int)roots.size() < n) {
      int k = __builtin_ctz(roots.size());
      roots.resize(n);
      while ((1 << k) < n) {
        auto e = pow(g, (M - 1) >> (k + 1));
        for (int i = 1 << (k - 1); i < (1 << k); ++i) {
          roots[2 * i] = roots[i];
          roots[2 * i + 1] = roots[i] * e;
        }
        ++k;
      }
    }
    for (int i = 0; i < n; ++i)
      if (rev[i] < i) {
        std::swap(a[i], a[rev[i]]);
      }
    for (int k = 1; k < n; k *= 2) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; ++j) {
          auto u = a[i + j], v = a[i + j + k] * roots[k + j];
          a[i + j] = u + v;
          a[i + j + k] = u - v;
        }
      }
    }
  }
  void idft(std::vector<MInt<M>>& a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    auto inv = pow(MInt<M>(n), M - 2);
    for (auto& x : a) x *= inv;
  }
};

// 多项式底层基类（不能放带 PolyBase 返回值的，不然很麻烦）
template <typename T>
class PolyBase {
 protected:
  void standard() {
    while (!a.empty() && a.back() == 0) a.pop_back();
  }
  void reverse() {
    std::reverse(a.begin(), a.end());
    standard();
  }

 public:
  std::vector<T> a;
  PolyBase() {}
  PolyBase(T x) {
    if (x != 0) a = {x};
  }
  PolyBase(const std::vector<T>& _a) : a(_a) { standard(); }
  int size() const { return a.size(); }
  T& operator[](int id) { return a[id]; }
  T at(int id) const {
    if (id < 0 || id >= (int)a.size()) return 0;
    return a[id];
  }
};

template <typename T>
class PolyBaseOrigin : public PolyBase<T> {
 public:
  using PolyBase<T>::PolyBase;
  PolyBaseOrigin(const PolyBase<T>& x) : PolyBase<T>(x) {}

 protected:
  PolyBaseOrigin mul(const PolyBaseOrigin& rhs) const {
    std::vector<T> ans(this->size() + rhs.size() - 1);
    for (int i = 0, sn = this->size(); i < sn; ++i) {
      for (int j = 0, rsn = rhs.size(); j < rsn; ++j) {
        ans[i + j] += this->a[i] * rhs.a[j];
      }
    }
    return PolyBaseOrigin(ans);
  }
};

template <int N>
class PolyBaseNTT : public PolyBase<MInt<N>> {
 protected:
  PolyBaseNTT mul(const PolyBaseNTT& rhs) const {
    int n = this->size(), m = rhs.size(), tot = std::max(1, n + m - 1);
    int sz = 1 << std::__lg(tot * 2 - 1);
    auto A = this->a, B = rhs.a;
    A.resize(sz);
    B.resize(sz);
    ntt.dft(A);
    ntt.dft(B);
    for (int i = 0; i < sz; ++i) A[i] *= B[i];
    ntt.idft(A);
    A.resize(n + m - 1);
    return PolyBaseNTT(A);
  }

 public:
  static inline const int M = N;
  static inline NTT<N> ntt;
  using PolyBase<MInt<N>>::PolyBase;
  PolyBaseNTT(const PolyBase<MInt<N>>& A) : PolyBase<MInt<N>>(A) {}
};

template <typename T>
class PolyBaseMFT3 : public PolyBase<T> {
 public:
  static inline constexpr int M0 = 469762049, M1 = 998244353, M2 = 1004535809;
  static inline constexpr LL M01 = 1LL * M0 * M1;
  static inline constexpr int t0 = 554580198, t1 = 395249030;
  static inline NTT<M0> ntt0;
  static inline NTT<M1> ntt1;
  static inline NTT<M2> ntt2;
  using PolyBase<T>::PolyBase;
  PolyBaseMFT3(const PolyBase<T>& x) : PolyBase<T>(x) {}

 protected:
  static T crt(int a0, int a1, int a2) {
    static const T m01(M01);
    LL x = (a0 + 1LL * (a1 - a0) * t0 % M1 * M0) % M01;
    if (x < 0) x += M01;
    LL y = (a2 - x) % M2;
    if (y < 0) y += M2;
    y = y * t1 % M2;
    if (y < 0) y += M01;
    return T(x) + T(y) * m01;
  }
  PolyBaseMFT3 mul(const PolyBaseMFT3& rhs) const {
    int tot = std::max(1, this->size() + rhs.size() - 1);
    int sz = 1 << std::__lg(tot * 2 - 1);
    std::vector<MInt<M0>> a0(sz), b0(sz);
    std::vector<MInt<M1>> a1(sz), b1(sz);
    std::vector<MInt<M2>> a2(sz), b2(sz);
    for (int i = 0, ns = this->size(); i < ns; ++i) {
      int t = this->a[i];
      a0[i] = t;
      a1[i] = t;
      a2[i] = t;
    }
    for (int i = 0, ns = rhs.size(); i < ns; ++i) {
      int t = rhs.a[i];
      b0[i] = t;
      b1[i] = t;
      b2[i] = t;
    }
    ntt0.dft(a0);
    ntt0.dft(b0);
    ntt1.dft(a1);
    ntt1.dft(b1);
    ntt2.dft(a2);
    ntt2.dft(b2);
    for (int i = 0; i < sz; ++i) {
      a0[i] *= b0[i];
      a1[i] *= b1[i];
      a2[i] *= b2[i];
    }
    ntt0.idft(a0);
    ntt1.idft(a1);
    ntt2.idft(a2);
    std::vector<T> ans(tot);
    for (int i = 0; i < tot; ++i) ans[i] = crt(a0[i], a1[i], a2[i]);
    return PolyBaseMFT3(ans);
  }
};

// 为什么用 4 模数 NTT 而不是两个 LL（int128 太耗时）
class PolyBaseMFT4 : public PolyBase<ModLL> {
 public:  // 都 4 模数了肯定是用 ModLL 啦，ctz(Mi) = 23, 所以 N 上限 4e6！
  static inline constexpr int M0 = 595591169, M1 = 645922817, M2 = 897581057,
                M3 = 998244353;
  static inline constexpr LL M01 = 1LL * M0 * M1, M23 = 1LL * M2 * M3;
  static inline constexpr __int128 M0123 = __int128(M01) * M23;
  static inline constexpr int t01 = 538269027, t23 = 415935157;
  static inline constexpr LL t0123 = 341204425684314487LL;
  static inline NTT<M0> ntt0;
  static inline NTT<M1> ntt1;
  static inline NTT<M2> ntt2;
  static inline NTT<M3> ntt3;
  using PolyBase<ModLL>::PolyBase;
  PolyBaseMFT4(const PolyBase<ModLL>& x) : PolyBase<ModLL>(x) {}

 protected:
  static ModLL crt(int a0, int a1, int a2, int a3) {
    LL ans1 = a0 + LL(a1 - a0) * t01 % M1 * M0;
    LL ans2 = a2 + LL(a3 - a2) * t23 % M3 * M2;
    __int128 ans = ans1 + __int128(ans2 - ans1) * t0123 % M23 *
                  M01;  // ans 不可能大于 M0123
    if (ans < 0) ans += M0123;
    return ModLL(ans);
  }
  PolyBaseMFT4 mul(const PolyBaseMFT4& rhs) const {
    int tot = std::max(1, this->size() + rhs.size() - 1);
    int sz = 1 << std::__lg(tot * 2 - 1);
    std::vector<MInt<M0>> a0(sz), b0(sz);
    std::vector<MInt<M1>> a1(sz), b1(sz);
    std::vector<MInt<M2>> a2(sz), b2(sz);
    std::vector<MInt<M3>> a3(sz), b3(sz);
    for (int i = 0, ns = this->size(); i < ns; ++i) {
      LL tmp = this->a[i];
      a0[i] = tmp;
      a1[i] = tmp;
      a2[i] = tmp;
      a3[i] = tmp;
    }
    for (int i = 0, ns = rhs.size(); i < ns; ++i) {
      LL tmp = rhs.a[i];
      b0[i] = tmp;
      b1[i] = tmp;
      b2[i] = tmp;
      b3[i] = tmp;
    }
    ntt0.dft(a0);
    ntt0.dft(b0);
    ntt1.dft(a1);
    ntt1.dft(b1);
    ntt2.dft(a2);
    ntt2.dft(b2);
    ntt3.dft(a3);
    ntt3.dft(b3);
    for (int i = 0; i < sz; ++i) {
      a0[i] *= b0[i];
      a1[i] *= b1[i];
      a2[i] *= b2[i];
      a3[i] *= b3[i];
    }
    ntt0.idft(a0);
    ntt1.idft(a1);
    ntt2.idft(a2);
    ntt3.idft(a3);
    std::vector<ModLL> ans(tot);
    for (int i = 0; i < tot; ++i) ans[i] = crt(a0[i], a1[i], a2[i], a3[i]);
    return PolyBaseMFT4(ans);
  }
};

namespace FFT {
const double PI = std::acos(-1);
using C = std::complex<double>;
std::vector<int> rev;
std::vector<C> roots{C(0, 0), C(1, 0)};
void dft(std::vector<C>& a) {
  int n = a.size();
  if ((int)rev.size() != n) {
    int k = __builtin_ctz(n) - 1;
    rev.resize(n);
    for (int i = 0; i < n; ++i) {
      rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
  }
  if ((int)roots.size() < n) {
    int k = __builtin_ctz(roots.size());
    roots.resize(n);
    while ((1 << k) < n) {
      C e = std::polar(1.0, PI / (1 << k));
      for (int i = 1 << (k - 1); i < (1 << k); ++i) {
        roots[2 * i] = roots[i];
        roots[2 * i + 1] = roots[i] * e;
      }
      ++k;
    }
  }
  for (int i = 0; i < n; ++i)
    if (rev[i] < i) {
      std::swap(a[i], a[rev[i]]);
    }
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; ++j) {
        auto u = a[i + j], v = a[i + j + k] * roots[k + j];
        a[i + j] = u + v;
        a[i + j + k] = u - v;
      }
    }
  }
}
void idft(std::vector<C>& a) {
  int n = a.size();
  std::reverse(a.begin() + 1, a.end());
  dft(a);
  for (auto& x : a) x /= n;
}
}  // namespace FFT
// 模板例题：https://www.luogu.com.cn/problem/P3803

// 当 N 特别大，或者数据处于 LL 就要慎重使用了
template <typename T>
class PolyBaseFFT : public PolyBase<T> {
 protected:
  PolyBaseFFT mul(const PolyBaseFFT& rhs) const {
    int tot = std::max(1, this->size() + rhs.size() - 1);
    int sz = 1 << std::__lg(tot * 2 - 1);
    // 为了保证精度必须拆分（否则直接用 三次变两次 技巧）
    auto A1(*this), A2(*this), B1(rhs), B2(rhs);
    static constexpr int bit = 15, msk = (1LL << bit) - 1;
    for (auto& x : A1.a) x &= msk;
    for (auto& x : A2.a) x >>= bit;
    for (auto& x : B1.a) x &= msk;
    for (auto& x : B2.a) x >>= bit;
    std::vector<std::complex<double>> A(sz), B(sz), C(sz);
    for (int i = 0, tSize = this->size(); i < tSize; ++i) {
      A[i] = std::complex<double>((double)A1[i], (double)A2[i]);
    }
    for (int i = 0, rSize = rhs.size(); i < rSize; ++i) {
      B[i] = std::complex<double>((double)B1[i], (double)B2[i]);
    }
    FFT::dft(A);
    FFT::dft(B);
    C[0] = conj(B[0]);
    for (int i = 1; i < sz; ++i) C[i] = conj(B[sz - i]);
    for (int i = 0; i < sz; ++i) B[i] *= A[i];
    for (int i = 0; i < sz; ++i) C[i] *= A[i];
    FFT::idft(B);
    FFT::idft(C);
    std::vector<T> ans(tot), A1B2(tot), A1B1(tot);
    // 这里会丢掉很多精度，怎么优化呢
    for (int i = 0; i < tot; ++i) {
      A1B2[i] = llround(B[i].imag());
      A1B1[i] = llround(B[i].real() * 0.5 + C[i].real() * 0.5);
      ans[i] = llround(C[i].real() * 0.5 - B[i].real() * 0.5);
    }
    for (auto& x : ans) x <<= bit;
    for (int i = 0; i < tot; ++i) ans[i] += A1B2[i];
    for (auto& x : ans) x <<= bit;
    for (int i = 0; i < tot; ++i) ans[i] += A1B1[i];
    return PolyBaseFFT(ans);
  }

 public:
  using PolyBase<T>::PolyBase;
  PolyBaseFFT(const PolyBase<T>& x) : PolyBase<T>(x) {}
};

// using valT = decltype(T::a)::value_type;
template <typename T, typename valT>
class Poly : public T {
 public:
  using T::T;
  Poly(const T& x) : T(x) {}
  Poly mulXn(int n) const {
    auto b = this->a;
    b.insert(b.begin(), n, 0);
    return Poly(b);
  }
  Poly modXn(int n) const {
    if (n > this->size()) return *this;
    return Poly({this->a.begin(), this->a.begin() + n});
  }
  Poly divXn(int n) const {
    if (this->size() <= n) return Poly();
    return Poly({this->a.begin() + n, this->a.end()});
  }
  Poly& operator+=(const Poly& rhs) {
    if (this->size() < rhs.size()) this->a.resize(rhs.size());
    for (int i = 0; i < rhs.size(); ++i) this->a[i] += rhs.a[i];
    this->standard();
    return *this;
  }
  Poly& operator-=(const Poly& rhs) {
    if (this->size() < rhs.size()) this->a.resize(rhs.size());
    for (int i = 0; i < rhs.size(); ++i) this->a[i] -= rhs.a[i];
    this->standard();
    return *this;
  }
  Poly operator+(const Poly& rhs) const { return Poly(*this) += rhs; }
  Poly operator-(const Poly& rhs) const { return Poly(*this) -= rhs; }
  Poly operator*(const Poly& rhs) const { return this->mul(rhs); }
  Poly& operator*=(const Poly& rhs) { return (*this) = (*this) * rhs; }
  Poly inv(int n) const {
    // assert(this->a[0] != 0);
    Poly x(this->a[0].inv());
    int k = 1;
    while (k < n) {
      k *= 2;
      x *= (Poly(2) - this->modXn(k) * x).modXn(k);
    }
    return x.modXn(n);
  }
  Poly& operator/=(Poly rhs) {
    int n = this->size(), m = rhs.size();
    if (n < m) return (*this) = Poly();
    this->reverse();
    rhs.reverse();
    (*this) *= rhs.inv(n - m + 1);
    this->a.resize(n - m + 1);
    this->reverse();
    return *this;
  }
  Poly operator/(const Poly& rhs) const { return Poly(*this) /= rhs; }
  Poly& operator%=(const Poly& rhs) { return *this -= (*this) / rhs * rhs; }
  Poly operator%(const Poly& rhs) const { return Poly(*this) %= rhs; }
  Poly powModPoly(LL n, const Poly& p) const {
    Poly r(1), x(*this);
    while (n) {
      if (n & 1) r = r * x % p;
      n >>= 1;
      x = x * x % p;
    }
    return r;
  }
  valT inner(const Poly& rhs) const {
    valT r(0);
    int n = std::min(this->size(), rhs.size());
    for (int i = 0; i < n; ++i) r += this->a[i] * rhs.a[i];
    return r;
  }
  Poly derivation() const {
    if (this->a.empty()) return Poly();
    int n = this->size();
    std::vector<valT> r(n - 1);
    for (int i = 1; i < n; ++i) r[i - 1] = this->a[i] * valT(i);
    return Poly(r);
  }
  Poly integral() const {
    if (this->a.empty()) return Poly();
    int n = this->size();
    std::vector<valT> r(n + 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i)
      inv[i] = valT(valT::mod() - valT::mod() / i) * inv[valT::mod() % i];
    for (int i = 0; i < n; ++i) r[i + 1] = this->a[i] * inv[i + 1];
    return Poly(r);
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
      x = (x * (Poly(1) - x.log(k) + this->modXn(k))).modXn(k);
    }
    return x.modXn(n);
  }
  // 需要保证首项为 1，开任意次方可以先 ln 再 exp 实现。
  Poly sqrt(int n) const {
    Poly x(1), inv2 = valT(2).inv();
    int k = 1;
    while (k < n) {
      k *= 2;
      x += this->modXn(k) * x.inv(k);
      x = x.modXn(k) * inv2;
    }
    return x.modXn(n);
  }
  // 减法卷积，也称转置卷积 {\rm MULT}(F(x),G(x))=\sum_{i\ge0}(\sum_{j\ge
  // 0}f_{i+j}g_j)x^i
  Poly mulT(Poly rhs) const {
    if (rhs.size() == 0) return Poly();
    int n = rhs.size();
    std::reverse(rhs.a.begin(), rhs.a.end());
    return ((*this) * rhs).divXn(n - 1);
  }
  valT eval(valT x) const {
    valT r(0), t(1);
    for (int i = 0, n = this->size(); i < n; ++i) {
      r += this->a[i] * t;
      t *= x;
    }
    return r;
  }
  // 多点求值新科技：https://jkloverdcoi.github.io/2020/08/04/转置原理及其应用/
  std::vector<valT> evals(std::vector<valT> x) const {
    if (this->size() == 0) return std::vector<valT>(x.size());
    int n = x.size();
    std::vector<valT> ans(n);
    std::vector<Poly> g(4 * n);
    std::function<void(int, int, int)> build = [&](int l, int r, int p) {
      if (r - l == 1) {
        g[p] = Poly({1, -x[l]});
      } else {
        int m = (l + r) / 2;
        build(l, m, 2 * p);
        build(m, r, 2 * p + 1);
        g[p] = g[2 * p] * g[2 * p + 1];
      }
    };
    build(0, n, 1);
    std::function<void(int, int, int, const Poly& )> solve =
      [&](int l, int r, int p, const Poly& f) {
        if (r - l == 1) {
          ans[l] = f.at(0);
        } else {
          int m = (l + r) / 2;
          solve(l, m, 2 * p, f.mulT(g[2 * p + 1]).modXn(m - l));
          solve(m, r, 2 * p + 1, f.mulT(g[2 * p]).modXn(r - m));
        }
      };
    solve(0, n, 1, mulT(g[1].inv(this->size())).modXn(n));
    return ans;
  }  // 模板例题：https://www.luogu.com.cn/problem/P5050

  // 计算 \sum_{i = 0}^{n - 1} a_i / (1 - b_i x)
  static std::vector<valT> sumFraction(std::vector<valT> a,
                     std::vector<valT> b, int N) {
    std::function<std::pair<Poly, Poly>(int, int)> solve =
      [&](int l, int r) -> std::pair<Poly, Poly> {
      if (r - l == 1) {
        return {Poly(a[l]), Poly({1, -b[l]})};
      }
      int m = (l + r) / 2;
      auto [pl, ql] = solve(l, m);
      auto [pr, qr] = solve(m, r);
      return {pl * qr + pr * ql, ql * qr};
    };
    auto [p, q] = solve(0, a.size());
    p *= q.inv(N);
    auto ans = p.a;
    ans.resize(N);
    return ans;
  }  // 模板例题：https://codeforces.com/gym/102978/problem/D

  // $a_n = \sum_{i = 1}^{k} f_i a_{n -
  // i}$，理论：https://oi-wiki.org/math/linear-recurrence/ $O(k \log k \log
  // n)$ 求 k 阶常系数递推公式的第 n 项
  static valT linearRecursion(std::vector<valT> a, std::vector<valT> f,
                int n) {
    if (n < a.size()) return a[n];
    int m = f.size();
    std::reverse(f.begin(), f.end());
    std::vector<valT> g(m);
    g.emplace_back(1);
    Poly A = Poly({0, 1}), p = Poly(g) - Poly(f);
    Poly R = A.powModPoly(n, p);
    return R.inner(a);
  }  // 模板: https://www.luogu.com.cn/problem/P4723

  // ans[i] = 1^i + 2^i + ... + (n - 1)^i, 0 < i < k
  // 原理：https://dna049.com/fastPowSumOfNaturalNumber/
  static std::vector<valT> prefixPowSum(int n, int k) {
    Poly Numerator = Poly({0, n}).exp(k + 1).divXn(1);
    Poly denominator = Poly({0, 1}).exp(k + 1).divXn(1);
    auto f = (Numerator * denominator.inv(k)).modXn(k) - Poly(1);
    auto ans = f.a;
    ans.resize(k);
    valT now(1);
    for (int i = 2; i < k; ++i) {
      now *= valT(i);
      ans[i] *= now;
    }
    return ans;
  }
  // 计算 $\prod_{i = 0}^{n - 1} (x + i)$
  static Poly prod(int n) {
    std::function<Poly(int l, int r)> solve = [&](int l, int r) -> Poly {
      if (r - l == 1) {
        return Poly({l, 1});
      } else {
        int m = (l + r) / 2;
        return solve(l, m) * solve(m, r);
      }
    };
    return solve(0, n);
  }
};  // 多项式全家桶测试：https://www.luogu.com.cn/training/3015#information

const constexpr int NTTM = 998244353;
using PolyNTT = Poly<PolyBaseNTT<NTTM>, MInt<NTTM>>;

const constexpr int FFTM = 1e9 + 7;
using PolyFFT = Poly<PolyBaseFFT<MInt<FFTM>>, MInt<FFTM>>;
using PolyFFTDynamic = Poly<PolyBaseFFT<ModInt>, ModInt>;
// 请勿使用，精度直接爆炸！
using PolyFFTLL = Poly<PolyBaseFFT<ModLL>, ModLL>;

// 这个较慢，仅供参考
using PolyMFT3 = Poly<PolyBaseMFT3<MInt<FFTM>>, MInt<FFTM>>;
using PolyMFTDynamic = Poly<PolyBaseMFT3<ModInt>, ModInt>;

// 四模数 NTT，由于一般 N 最大为 1e6，所以 M 最大可到 1e14
using PolyMFT = Poly<PolyBaseMFT4, ModLL>;

// 这个是原始的，可用于对拍
using PolyOrigin = Poly<PolyBaseOrigin<MInt<FFTM>>, MInt<FFTM>>;
using PolyOriginDynamic = Poly<PolyBaseOrigin<ModInt>, ModInt>;

/*
8 case donated by
{, , }, {, 111, 111}, {, 1, 11}, {1, , 11}, {, 01, 11}, {, , 111}, {, 11, 1},
{1, 11, } and matirx A = [1 1 1 1 1 0 0 0] [0 0 1 0 0 1 1 0] [1 0 0 0 0 0 0 1]
[0 0 1 0 0 0 0 0]
[1 0 0 0 0 0 0 0]
[1 0 0 0 0 0 0 0]
[1 0 0 1 0 0 0 0]
[1 0 0 1 0 0 0 0]
b = [1 0 0 0 0 0 0 0]^T
and the answer is (A^n b)[0]
charPoly(A) = x^8 - x^7 - 2*x^6 - 6*x^5 - x^4 + x^2
so we only need b[0], (Ab)[0],..., (A^7 b)[0] = (1, 1, 3, 10, 23, 62, 170, 441)
using sageMath
A = matrix(8)
A[:, 0] = A[0, :] = A[1, 2] = A[1, 5] = A[1, 6] = A[2, 7] = A[3, 2] = A[6,3] =
A[7, 3] = 1 A[0, 5] = A[0, 6] = A[0, 7] = A[1, 0] = A[3, 0] = 0 b = matrix(8, 1)
b[0] = 1
for i in range(8):
  print((A^i * b)[0])

有些关系可以被优化，于是我们得到了如下做法：
*/

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  PolyOrigin mod({1, 0, -1, -6, -2, -1, 1});
  std::vector<MInt<FFTM>> b{1, 1, 3, 10, 23, 62};
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL n;
    std::cin >> n;
    PolyOrigin A({0, 1});
    auto B = A.powModPoly(n, mod);
    MInt<FFTM> ans = 0;
    for (int i = 0; i < 6; ++i) ans += B.at(i) * b[i];
    std::cout << ans << '\n';
  }
  return 0;
}