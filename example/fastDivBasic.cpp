#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<typename T>
int ctz(T x) {
  if (sizeof(T) == 4) return __builtin_ctz(x);
  return __builtin_ctzll(x);
}

template<typename T, typename T2>
std::pair<int, T2> chooseMultiplier(T d) {
  constexpr int bitLen = __CHAR_BIT__ * sizeof(T);
  if ((d & -d) == d) return {ctz(d), T2(1)};
  T2 lb = T2(1) << bitLen;
  int l = std::__lg(d - 1) + 1;
  while (l >= 0 && (lb << l) / d != (lb + 1 << l) / d) --l;
  ++l;
  return {l, (lb + 1 << l) / d};
}

void generateUnsignedDivision(uint32_t d) {
  assert(d != 0);
  int dd = ctz(d);
  std::cout << "inline uint32_t div" << d << "(uint32_t n) {\n";
  if (d >= 1u << 31) {
    std::cout << "  return n >= " << d << ";\n";
  } else if (d == 1 << dd) {
    std::cout << "  return n";
    if (dd) std::cout << " >> " << dd;
    std::cout << ";\n";
  } else {
    auto [l, m] = chooseMultiplier<uint32_t, uint64_t>(d);
    if (m < 1ull << 32) {
      std::cout << "  return " << m  << "ull * n >> " << l + 32 << ";\n";
    } else if (dd == 0) {
      std::cout << "  uint32_t t = " << (m - (1ull << 32)) << "ull * n >> 32;\n";
      std::cout << "  return (n - t >> 1) + t";
      if (l > 1) std::cout << " >> " << l - 1;
      std::cout << ";\n";
    } else {
      auto [l2, m2] = chooseMultiplier<uint32_t, uint64_t>(d >> 1);
      std::cout << "  return " << m2  << "ull * (n >> 1) >> " << l2 + 32 << ";\n";
    }
  }
  std::cout << "}\n\n";
}

// only for gcc and x86_64
void generateUnsignedDivisionAsm(uint32_t d) {
  assert(d != 0);
  int dd = ctz(d);
  std::cout << "inline uint32_t div" << d << "Asm(uint32_t n) {\n";
  if (d >= 1u << 31) {
    std::cout << "  return n >= " << d << ";\n";
  } else if (d == (1 << dd)) {
    std::cout << "  return n";
    if (dd) std::cout << " >> " << dd;
    std::cout << ";\n";
  } else {
    auto [l, m] = chooseMultiplier<uint32_t, uint64_t>(d);
    if (m < (1ull << 32)) {
      std::cout << "  return muluh(" << m  << ", n)";
      if (l > 0) std::cout << " >> " << l;
      std::cout << ";\n";
    } else if (dd == 0) {
      std::cout << "  uint32_t t = " << "muluh(" << m - (1ull << 32) << ", n);\n";
      std::cout << "  return (n - t >> 1) + t";
      if (l > 1) std::cout << " >> " << l - 1;
      std::cout << ";\n";
    } else {
      auto [l2, m2] = chooseMultiplier<uint32_t, uint64_t>(d >> 1);
      std::cout << "  return muluh(" << m2  << ", n >> 1)";
      if (l2 > 0) std::cout << " >> " << l2;
      std::cout << ";\n";
    }
  }
  std::cout << "}\n\n";
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

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}