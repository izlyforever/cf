#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
template<typename T>
using SignedT = std::enable_if_t<std::is_signed_v<T>>;

template<typename T>
using IntLongT = std::enable_if_t<
    std::is_same_v<int32_t, T>  ||
    std::is_same_v<uint32_t, T> ||
    std::is_same_v<int64_t, T>  ||
    std::is_same_v<uint64_t, T>>;

template<typename T, typename enable = IntLongT<T>>
int ctz(T x) {
  if constexpr (sizeof(T) == 4) return __builtin_ctz(x);
  return __builtin_ctzll(x);
}

template<typename T>
std::tuple<T, T, T> exGcd(T a, T b) {
  if (b == 0) return {a, 1, 0};
  auto [d, y, x] = exGcd(b, a % b);
  return {d, x, y - a / b * x};
}

template<typename T, typename T2>
using TwiceT = std::enable_if_t<sizeof(T) * 2 == sizeof(T2)>;

template<typename T, typename T2, typename enable = TwiceT<T, T2>>
T inv(T x, T M) {
  return x == 1 ? x : T2(M - M / x) * inv<T, T2>(M % x, M) % M;
}
template<typename T>
using UnsignedT = std::enable_if_t<std::is_unsigned_v<T>>;

template<typename T, typename T2, int Bit = 4 * sizeof (T), 
    typename enable1 = TwiceT<T, T2>, 
    typename enable2 = UnsignedT<T>>
    // typename enable3 = UnsignedT<T2>>
class fastPowMod {
  static inline bool flag;
  static inline T m_ = 0, mr_, m1_, m1inv_;
  void init() {
    flag = (m_ & -m_) == m_;
    if (!flag) {
      assert(m_ & 1);
      m1_ = (T(1) << Bit) % m_;
      m1inv_ = inv<T, T2>(m1_, m_);
      if constexpr(4 == sizeof (T)) {
        auto [d, x, y] = exGcd(int64_t(1) << Bit, int64_t(m_));
        y = -y;
        if (y < 0) y += int64_t(1) << Bit;
        mr_ = y;
      } else {
        auto [d, x, y] = exGcd(__int128(1) << Bit, __int128(m_));
        y = -y;
        if (y < 0) y += __int128(1) << Bit;
        mr_ = y;
      }
    }
  }
 public:
  fastPowMod() {}
  fastPowMod(T m) { setMod(m);}
  void setMod(T m) {
    m_ = m;
    assert(m_);
    init();
  }
  T getAns(T x, T n) {
    assert(m_);
    if (flag) {
      T r = 1;
      while (n) {
        if (n & 1) r = T2(r) * x & m_ - 1;
        n >>= 1;   x = T2(x) * x & m_ - 1;
      }
      return r;
    }
    x = (T2(x) << Bit) % m_;
    T r = m1_;
    while (n) {
      if (n & 1) {
        T2 t = T2(r) * x;
        r = (t + T2(T(t) * mr_) * m_) >> Bit;
      }
      T2 t = T2(x) * x;
      x = (t + T2(T(t) * mr_) * m_) >> Bit;
      n >>= 1;
    }
    return T2(r) * m1inv_ % m_;
  }
};

int main() {
  fastPowMod<uint32_t, uint64_t> A32;
  A32.setMod(11);
  cerr(A32.getAns(3, 3));

  fastPowMod<uint64_t, __uint128_t> A64;
  A64.setMod(11);
  cerr(A64.getAns(3, 3));
  return 0;
}