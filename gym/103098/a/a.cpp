#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;


template<int N>
class MInt {
  static inline constexpr int M = N;
  int n;
  static int inv(int x) {
    // assert(std::gcd(x, M) == 1);
    return x == 1 ? x : 1LL * (M - M / x) * inv(M % x) % M;
  }
 public:
  static void setMod(int m) {
    M = m;
  }
  static constexpr int mod() {
    return M;
  }
  // 请自行确保 0 <= x < M
  static MInt raw(int x) {
    MInt A;
    A.n = x;
    return A;
  }
  MInt(LL x = 0) : n(x % M) {
    if (n < 0) n += M;
  }
  operator int() const {
    return n;
  }
  MInt operator-() const {
    return n == 0 ? *this : raw(M - n);
  }
  MInt& operator++() {
    if (++n == M) n = 0;
    return *this;
  }
  MInt& operator--() {
    if (--n == -1) n += M;
    return *this;
  }
  MInt& operator+=(const MInt &A) {
    n += A.n;
    if (n >= M) n -= M;
    return (*this);
  }
  MInt& operator-=(const MInt &A) {
    n -= A.n;
    if (n < 0) n += M;
    return (*this);
  }
  MInt& operator*=(const MInt &A) {
    n = 1LL * n * A.n % M;
    return (*this);
  }
  MInt& operator/=(const MInt &A) {
    return (*this) *= A.inv();
  }
  MInt operator+(const MInt &A) const {
    return MInt(*this) += A;
  }
  MInt operator-(const MInt &A) const {
    return MInt(*this) -= A;
  }
  MInt operator*(const MInt &A) const {
    return MInt(*this) *= A;
  }
  MInt operator/(const MInt &A) const {
    return MInt(*this) /= A;
  }
  MInt operator<<(int x) const {
    LL r = n;
    r <<= x;
    return MInt(r);
  }
  MInt& operator<<=(int x) {
    return (*this) = (*this) << x;
  }
  MInt& operator>>=(int x) {
    n >>= x;
    return (*this);
  }
  MInt operator>>(int x) const {
    return MInt(*this) >> x;
  }
  MInt operator&(int x) const {
    return MInt(*this) & x;
  }
  MInt& operator&=(int x) {
    n &= x;
    return (*this);
  }
  MInt inv() const {
    return inv(n);
  }
  friend MInt pow(MInt A, int n) {
    MInt R(1);
    while (n) {
      if (n& 1) R *= A;
      n >>= 1;  A *= A;
    }
    return R;
  }
  friend std::istream &operator>>(std::istream &in, MInt &A) {
    LL x;
    in >> x;
    A = MInt(x);
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const MInt &A) {
    out << A.n;
    return out;
  }
};

const int M = 1e9 + 7;
using Mod = MInt<M>;
// 设 a[n][k], b[n][k] 分别为 n 与 n - 1 不相连，相连的答案，则
// a[n][k] = (k + 1) a[n - 1][k + 1] + (n - 2 - k) a[n - 1][k] + k b[n - 1][k + 1] + (n - 1 - k) b[n - 1][k]
// b[n][k] = b[n - 1][k - 1] + b[n - 1][k] + a[n - 1][k - 1] * 2
const int N = 1002;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<std::vector<Mod>> a(N + 2, std::vector<Mod>(N + 2));
  auto b = a;
  a[1][0] = 1;
  for (int n = 2; n < N; ++n) {
    a[n][0] = a[n - 1][1] + a[n - 1][0] * Mod(n - 2);
    for (int k = 1; k < n; ++k) {
      a[n][k] = b[n - 1][k + 1] * Mod(k) + b[n - 1][k] * Mod(n - 1 - k);
      if (k + 1 < n) a[n][k] += a[n - 1][k + 1] * Mod(k + 1) + a[n - 1][k] * Mod(n - 2 - k);
      b[n][k] = b[n - 1][k - 1] + b[n - 1][k] + a[n - 1][k - 1] + a[n - 1][k - 1];
    }
  }
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::cout << a[n][k] + b[n][k] << '\n';
  }
  return 0;
}