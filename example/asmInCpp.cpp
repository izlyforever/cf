#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
using ULL = unsigned long long;

static inline  __attribute__((always_inline)) 
unsigned muluh(unsigned a, unsigned b, unsigned& c) {
  unsigned x;
  __asm__ __volatile__(
    "mull %%edx"
    : "=a"(c), "=d"(x)
    : "a"(a), "d"(b)
  );
  return x;
}
static inline  __attribute__((always_inline)) 
unsigned muluh(unsigned a, unsigned b) {
  unsigned x;
  __asm__ __volatile__(
    "mull %%edx"
    : "=d"(x)
    : "a"(a), "d"(b)
  );
  return x;
}

int main() {
  unsigned x, y, z;
  std::cin >> x >> y;
  cerr(muluh(x, y));
  cerr(muluh(x, y, z));
  return 0;
}
