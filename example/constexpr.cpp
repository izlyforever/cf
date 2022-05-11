#include <bits/stdc++.h>

template<int N>
struct Sieve {
  bool isP[N];
  // O(n log log n)
  constexpr Sieve() : isP() {
    isP[2] = true;
    for (int i = 3; i < N; i += 2) isP[i] = true;
    for (int i = 3, j = 9; j < N; i += 2, j = i * i) if (isP[i]) {
      while (j < N) isP[j] = false, j += i * 2;
    }
  }
};
constexpr int MAXN = 100000;
// constexpr int MAXN = 12345678;
// -fconstexpr-loop-limit (default: 1<<18=262144),
// -fconstexpr-ops-limit  (default: 1<<25=33554432)
// -fconstexpr-depth      (default:  1<<9=512)
// -ftemplate-depth       (default: 900)
// g++ main.cpp -std=c++17 -fconstexpr-loop-limit=12345678 -fconstexpr-ops-limit=1234567890 -fconstexpr-depth=100000 -ftemplate-depth=100000
bool fast_is_prime(int n) {
  static constexpr Sieve<MAXN> s;
  return s.isP[n];
}
constexpr bool isPrime(int n) {
  if (n < 2) return false;
  if (n < 4) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
};
// https://codeforces.com/blog/entry/79941

namespace v0 {
// assmue that i  is odd, i * i > n twice is needed, don't need 1LL * i * i > n
template <int n, int i>
struct PrimeChecker {
  using type =
      std::conditional_t<(i * i > n), std::true_type,
          std::conditional_t<(n % i == 0), std::false_type,
              typename PrimeChecker<n, (i * i > n) ? -1 : i + 2>::type>>;
};
template <int n>
struct PrimeChecker<n, -1> {
  using type = void;
};

template<int n>
struct IsPrime {
  using type =
      std::conditional_t<(n < 2 || n % 2 == 0), std::false_type,
          typename PrimeChecker<n, 3>::type>;
};
template<>
struct IsPrime<2> : public std::true_type {};
}  // namespace v0
// https://stackoverflow.com/q/18303632/17276415

constexpr int fastSqrt(int v) {
  unsigned temp = 0, nHat = 0, b = 0x8000, bshft = 15;
  do {
    if (v >= (temp = (((nHat << 1) + b) << bshft--))) {
      nHat += b;
      v -= temp;
    }
  } while (b >>= 1);
  return nHat;
}
// http://www.azillionmonkeys.com/qed/ulerysqroot.pdf

namespace {
// assmue that i  is odd
template <int n, int i>
struct PrimeChecker {
  using type =
      std::conditional_t<(i == 1), std::true_type,
          std::conditional_t<(n % i == 0), std::false_type,
              typename PrimeChecker<n, i - 2>::type>>;
};
template <int n>
struct PrimeChecker<n, 1> : public std::true_type {};

template<int n>
struct IsPrime {
  using type = std::conditional_t<(n < 2 || n % 2 == 0), std::false_type,
              typename PrimeChecker<n, fastSqrt(n) | 1>::type>;
};
template<>
struct IsPrime<2> : public std::true_type {};
}  // namespace

// too slow and may have complier error in gcc11 for big n
constexpr bool isPrimeR(int n, int c) {
  return c * c > n ? true : n % c == 0 ? false : isPrimeR(n, c + 2);
}
constexpr bool isPrimeConstexpr(int n) {
  return n < 2 ? false : n < 4 || (n % 2 == 1 && isPrimeR(n, 3));
}
// https://stackoverflow.com/questions/18303632/compile-time-prime-checking


class Timer final {
  std::chrono::high_resolution_clock::time_point start_;
  std::string name_;
 public:
  Timer(std::string name = {}) : start_(std::chrono::high_resolution_clock::now()), name_(name) {}
  ~Timer() {
    auto elapsedTime = std::chrono::high_resolution_clock::now() - start_;
    std::cerr << std::setprecision(3) << std::fixed << "[Time used: " <<
        name_ << "] " << elapsedTime.count() / 1'000'000.0 << "ms\n";
  }
  static std::string nowTime() {
    time_t t = time(0);
    char buffer[9] = {0};
    strftime(buffer, 9, "%H:%M:%S", localtime(&t));
    return std::string(buffer);
  }
};

// g++-11 constexpr.cpp -std=c++17 -fconstexpr-loop-limit=12345678 -fconstexpr-ops-limit=1234567890 -fconstexpr-depth=100000 -ftemplate-depth=100000
int main() {
  {
    constexpr int m = 7919 * 7927;
    constexpr bool x = isPrimeConstexpr(m);
    std::cout << m << " is " <<  (x ? "prime" : "not prime") << '\n';
  }
  {
    constexpr int m = 998244353;
    constexpr bool x = isPrimeConstexpr(m);
    std::cout << m << " is " <<  (x ? "prime" : "not prime") << '\n';
  }
  {
    const int N = 1234567;
    std::vector<int> a(N);
    for (auto &x : a) x = rand() % MAXN;

    Timer A("constexpr");
    int cnt = 0;
    for (auto &x : a) if (fast_is_prime(x)) ++cnt;
    std::cout << cnt << '\n';
  }
  {
    Timer A("IsPrime");
    int cnt = 0;
    IsPrime<807955102>::type x0;
    IsPrime<281386577>::type x1;
    IsPrime<179424673>::type x2;
    IsPrime<504842251>::type x3;
    IsPrime<998244353>::type x4;
    if (x0) ++cnt;
    if (x1) ++cnt;
    if (x2) ++cnt;
    if (x3) ++cnt;
    if (x4) ++cnt;
    std::cout << cnt << '\n';
  }
  {
    Timer A("isPrime");
    int cnt = 0;
    bool x0 = isPrime(807955102);
    bool x1 = isPrime(281386577);
    bool x2 = isPrime(179424673);
    bool x3 = isPrime(504842251);
    bool x4 = isPrime(998244353);
    if (x0) ++cnt;
    if (x1) ++cnt;
    if (x2) ++cnt;
    if (x3) ++cnt;
    if (x4) ++cnt;
    std::cout << cnt << '\n';
  }
  {
    Timer A("isPrime2");
    int cnt = 0;
    if (isPrime(807955102)) ++cnt;
    if (isPrime(281386577)) ++cnt;
    if (isPrime(179424673)) ++cnt;
    if (isPrime(504842251)) ++cnt;
    if (isPrime(998244353)) ++cnt;
    std::cout << cnt << '\n';
  }
  return 0;
}
