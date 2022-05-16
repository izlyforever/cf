#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<typename T>
bool uless(T x, T y) {
  static_assert(std::is_unsigned_v<T>, "T must be unsigned");
  static constexpr T HalfT = T(1) << (std::numeric_limits<T>::digits - 1);
  return T(x - y) > HalfT;
}

using seq_t = uint16_t;
static inline bool lessThan(seq_t l, seq_t r) {
  return seq_t(l - r) >> (sizeof(seq_t) * CHAR_BIT - 1);
}
#define printLessThan(x, y) std::cout << #x "= " << x << (lessThan(x, y) ? " < " : " > ") << y << " =" #y << '\n'

void solve() {
  {
    uint16_t x1 = 0xffff;
    uint16_t x2 = 2u;
    uint16_t x3 = 0x7fff;
    uint16_t x4 = 0x9fff;
    printLessThan(x1, x2);
    printLessThan(x2, x3);
    printLessThan(x3, x4);
    printLessThan(x4, x1);

    printLessThan(x2, x1);
    printLessThan(x3, x2);
    printLessThan(x4, x3);
    printLessThan(x1, x4);
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
