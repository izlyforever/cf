#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
#define NewLine std::cerr << '\n'

template<typename T>
using IntLong = std::enable_if_t<
    std::is_same_v<int32_t, T>  ||
    std::is_same_v<uint32_t, T> ||
    std::is_same_v<int64_t, T>  ||
    std::is_same_v<uint64_t, T>>;

template<typename T, typename T2>
using Twice = std::enable_if_t<sizeof(T) * 2 == sizeof(T2)>;

template<typename T, typename check = IntLong<T>>
int ctz(T x) {
  if constexpr (sizeof(T) == 4) return __builtin_ctz(x);
  return __builtin_ctzll(x);
}

template<typename T, typename T2, typename check = Twice<T,T2>>
std::pair<int, T2> chooseMultiplier(T d) {
  constexpr int bitLen = __CHAR_BIT__ * sizeof(T);
  if ((d & -d) == d) return {ctz(d), T2(1)};
  T2 lb = T2(1) << bitLen;
  int l = std::__lg(d - 1) + 1;
  while (l >= 0 && (lb << l) / d != (lb + 1 << l) / d) --l;
  ++l;
  return {l, (lb + 1 << l) / d};
}

template<typename T, typename T2, typename check = Twice<T,T2>>
std::function<T(T)> getDivFun(T d) {
  assert(d != 0);
  constexpr int bitLen = __CHAR_BIT__ * sizeof(T);
  if (d >= T(1) << bitLen - 1) {
    return [d](T n) {
      return n >= d;
    };
  }
  int dd = ctz(d);
  if (d == 1 << dd) {
    return [dd](T n) {
      return n >> dd;
    };
  }
  auto [l, m] = chooseMultiplier<T, T2>(d);
  if (m < T2(1) << bitLen) {
    return [mf = m, lf = l + bitLen](T n) {
      return mf * n >> lf;
    };
  }
  if (dd == 0) {
    if (l > 1) {
      return [mf = m - (T2(1) << bitLen), lf = l - 1](T n) {
        T t = mf * n >> __CHAR_BIT__ * sizeof(T);
        return (n - t >> 1) + t >> lf;
      };
    } else {
      return [mf = m - (T2(1) << bitLen)](T n) {
        T t = mf * n >> __CHAR_BIT__ * sizeof(T);
        return (n - t >> 1) + t;
      };
    }
  }
  auto [l2, m2] = chooseMultiplier<T, T2>(d >> 1);
  return [mf = m2, lf = l2 + bitLen](T n) {
    return mf * (n >> 1) >> lf;
  };
}

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rnd64(std::chrono::steady_clock::now().time_since_epoch().count());
class Timer final {
  std::chrono::high_resolution_clock::time_point start_;
  std::string name_;
 public:
  Timer(std::string name = {}) : start_(std::chrono::high_resolution_clock::now()), name_(name) {}
  ~Timer() {
    auto elapsedTime = std::chrono::high_resolution_clock::now() - start_;
    std::cerr << std::setprecision(3) << std::fixed << "[Time used: " << name_ << "] " << elapsedTime.count() / 1'000'000.0 << "ms\n";
  }
};

inline uint32_t div14(uint32_t n) {
  return 4908534053ull * (n >> 1) >> 35;
}

int main() {
  const int N = 1e7 + 2;
  // test for mod = 14
  {
    std::vector<uint32_t> a(N);
    for (auto &x : a) x = rnd();
    const uint32_t modConst = 14;
    uint32_t mod = 14;
    for (auto x : a) {
      if (div14(x) != x / mod) {
        std::cerr << x << ' ' << div14(x) << ' ' << x / mod << '\n';
        return -1;
      }
    }
    {
      Timer A("mod14");
      uint64_t sum = 0;
      for (auto x : a) sum += div14(x);
      cerr(sum);
    }
    {
      Timer A("default");
      uint64_t sum = 0;
      for (auto x : a) sum += x / mod;
      cerr(sum);
    }
    {
      Timer A("const default");
      uint64_t sum = 0;
      for (auto x : a) sum += x / modConst;
      cerr(sum);
    }
  }
  NewLine;
  // test for uint32
  {
    std::vector<uint32_t> a(N);
    for (auto &x : a) x = rnd();
    uint32_t mod = 0;
    while ((mod = rnd()) == 0);
    auto f = getDivFun<uint32_t, u_int64_t>(mod);
    for (auto x : a) {
      if (f(x) != x / mod) {
        std::cerr << x << ' ' << f(x) << ' ' << x / mod << '\n';
        return -1;
      }
    }
    {
      Timer A("default");
      uint64_t sum = 0;
      for (auto x : a) sum += x / mod;
      cerr(sum);
    }
    {
      Timer A("fast?");
      uint64_t sum = 0;
      for (auto x : a) sum += f(x);
      cerr(sum);
    }
  }
  NewLine;
  // test for uint64
  {
    std::vector<uint64_t> a(N);
    for (auto &x : a) x = rnd();
    uint64_t mod = 0;
    while ((mod = rnd64()) == 0);
    mod = mod % INT_MAX; // avoid answer too small
    auto f = getDivFun<u_int64_t, __uint128_t>(mod);
    for (auto x : a) {
      if (f(x) != x / mod) {
        std::cerr << x << ' ' << f(x) << ' ' << x / mod << '\n';
        return -1;
      }
    }
    {
      Timer A("default");
      __uint128_t sum = 0;
      for (auto x : a) sum += x / mod;
      cerr(uint64_t(sum >> 64));
      cerr(uint64_t(sum));
    }
    {
      Timer A("fast?");
      __uint128_t sum = 0;
      for (auto x : a) sum += f(x);
      cerr(uint64_t(sum >> 64));
      cerr(uint64_t(sum));
    }
  }
}
