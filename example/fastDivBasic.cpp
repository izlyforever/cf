#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

std::pair<uint32_t, uint64_t> chooseMultiplier(uint32_t d, uint32_t bitLen = 32) {
  if ((d & -d) == d) return {std::__lg(d), 1};
  int l = std::__lg(d - 1) + 1;
  uint64_t lb = 1ull << bitLen;
  while (l >= 0 && (lb << l) / d != (lb + 1 << l) / d) --l;
  ++l;
  return {l, (lb + 1 << l) / d};
}

void generateUnsignedDivision(uint32_t d, uint32_t bitLen = 32) {
  assert(d != 0);
  auto dd = __builtin_ctz(d);
  std::cout << "uint32_t div" << d << "(uint32_t n) {\n";
  if (d >= 1u << bitLen - 1) {
    std::cout << "  return n >= " << d << ";\n";
  } else if (d == (1 << dd)) {
    std::cout << "  return n";
    if (dd) std::cout << " >> " << dd;
    std::cout << ";\n";
  } else {
    auto [l, m] = chooseMultiplier(d);
    if (m < (1ull << bitLen)) {
      std::cout << "  return " << m  << "ull * n >> " << l + bitLen << ";\n";
    } else if (dd == 0) {
      std::cout << "  uint32_t t = " << (m - (1ull << bitLen)) << "ull * n >> 32;\n";
      std::cout << "  return (n - t >> 1) + t";
      if (l > 1) std::cout << " >> " << l - 1;
      std::cout << ";\n";
    } else {
      auto [l2, m2] = chooseMultiplier(d >> 1, bitLen - 1);
      std::cout << "  return " << m2  << "ull * (n >> 1) >> " << l2 + bitLen << ";\n";
    }
  }
  std::cout << "}\n";
}

void generateUnsignedDivisionAsm(uint32_t d, uint32_t bitLen = 32) {
  assert(d != 0);
  auto dd = __builtin_ctz(d);
  std::cout << "uint32_t div" << d << "Asm(uint32_t n) {\n";
  if (d >= 1u << bitLen - 1) {
    std::cout << "  return n >= " << d << ";\n";
  } else if (d == (1 << dd)) {
    std::cout << "  return n";
    if (dd) std::cout << " >> " << dd;
    std::cout << ";\n";
  } else {
    auto [l, m] = chooseMultiplier(d);
    if (m < (1ull << bitLen)) {
      std::cout << "  return muluh(" << m  << ", n)";
      if (l > 0) std::cout << " >> " << l;
      std::cout << ";\n";
    } else if (dd == 0) {
      std::cout << "  uint32_t t = " << "muluh(" << m - (1ull << 32) << ", n);\n";
      std::cout << "  return (n - t >> 1) + t";
      if (l > 1) std::cout << " >> " << l - 1;
      std::cout << ";\n";
    } else {
      auto [l2, m2] = chooseMultiplier(d >> 1, bitLen - 1);
      std::cout << "  return muluh(" << m2  << ", n >> 1)";
      if (l2 > 0) std::cout << " >> " << l2;
      std::cout << ";\n";
    }
  }
  std::cout << "}\n";
}

void solve() {
  for (int i = 1; i < 16; ++i) {
    generateUnsignedDivision(i);
    generateUnsignedDivisionAsm(i);
  }
  uint32_t x = 6700417;
  // std::cin >> x;
  generateUnsignedDivision(x);
  generateUnsignedDivisionAsm(x);
}
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
class Timer final {
  std::chrono::high_resolution_clock::time_point start_;
  std::string name_;
 public:
  Timer(std::string name = {}) : start_(std::chrono::high_resolution_clock::now()), name_(name) {}
  ~Timer() {
    auto elapsedTime = std::chrono::high_resolution_clock::now() - start_;
    std::cerr << "[Time used: " << name_ << "] " << elapsedTime.count() / 1'000'000.0 << "ms\n";
  }
};

uint32_t div6700417(uint32_t n) {
  return 641ull * n >> 32;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int M = 6700417;
  const int N = 1e8 + 2;
  std::vector<uint32_t> a(N);
  for (int i = 0; i < N; ++i) a[i] = rnd();
  {
    Timer A("default");
    LL sum = 0;
    for (int i = 0; i < N; ++i) sum += a[i] / M;
    cerr(sum);
  }
  {
    Timer A("fast");
    LL sum = 0;
    for (int i = 0; i < N; ++i) sum += div6700417(a[i]);
    cerr(sum);
  }
  // {
  //   Timer A("fastAsm");
  //   LL sum = 0;
  //   for (int i = 0; i < N; ++i) sum += div6700417Asm(a[i]);
  //   cerr(sum);
  // }
  // solve();
  return 0;
}