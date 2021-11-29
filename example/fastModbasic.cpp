#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int powMod(int x, int n, int M) {
  int r = 1;
  while (n) {
    if (n&1) r = 1LL * r * x % M;
    n >>= 1; x = 1LL * x * x % M;
  }
  return r;
}

template<typename T>
std::tuple<T, T, T> exGcd(T a, T b) {
  if (b == 0) return {a, 1, 0};
  auto [d, y, x] = exGcd(b, a % b);
  return {d, x, y - a / b * x};
}

void generate(int m) {
  if ((m & -m) == m) {
    std::clog << "You may use bit operators instead:\n\n";
    std::cout << "unsigned fastPowMod" << m << "(unsigned x, unsigned n) {\n";
    std::cout << "  unsigned r = 1;\n";
    std::cout << "  while (n) {\n";
    std::cout << "    if (n & 1) r = 1LL * r * x &" <<  m - 1 << "U;\n";
    std::cout << "    n >>= 1;   r = 1LL * x * x &" <<  m - 1 << "U;\n";
    std::cout << "  }\n";
    std::cout << "  return r;\n";
    std::cout << "}\n\n";
    return;
  } else if (m % 2 == 0) {
    std::cerr << "Sorry, not support for even number which is not power of 2: " << m << "\n\n";
    return;
  } else if (m >> 30) {
    std::cerr << "Sorry, not support for number bigger than 2^30: " << m << "\n\n";
    return;
  }
  auto [d, x, y] = exGcd(1LL << 32, 1LL * m);
  y = -y;
  if (y < 0) y += 1LL << 32;
  std::cout << "using ULL = unsigned long long;\n";
  std::cout << "unsigned fastPowMod" << m << "(unsigned x, unsigned n) {\n";
  std::cout << "  static const unsigned m = " << m << "U;\n";
  std::cout << "  static const unsigned mr = " << y << "U;\n";
  std::cout << "  static const unsigned m1 = " << (1LL << 32) % m << "U;\n";
  std::cout << "  static const unsigned m1inv = " << powMod(2, 32LL * (m - 2) % (m - 1), m) << "U;\n";
  std::cout << "  unsigned xx = (ULL(x) << 32) % m, rr = m1;\n";
  std::cout << "  while (n) {\n";
  std::cout << "    if (n & 1) {\n";
  std::cout << "      ULL t = ULL(rr) * xx;\n";
  std::cout << "      rr = (t + ULL(unsigned(t) * mr) * m) >> 32;\n";
  std::cout << "    }\n";
  std::cout << "    ULL t = ULL(xx) * xx;\n";
  std::cout << "    xx = (t + ULL(unsigned(t) * mr) * m) >> 32;\n";
  std::cout << "    n >>= 1;\n";  
  std::cout << "  }\n";
  std::cout << "  return ULL(rr) * m1inv % m;\n";
  std::cout << "}\n\n";
}

int main() {
  generate(998244353);
  generate(1000000007);
  generate(1000000009);
  generate(1024);
  generate(24);
  generate((1 << 30) + 1);
  return 0;
}