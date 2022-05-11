#include <iostream>
using LL = long long;

constexpr bool isPrimeR(LL n, LL c) {
  return c * c > n ? true : n % c == 0 ? false : isPrimeR(n, c + 2);
}
constexpr bool isPrimeConstexpr(LL n) {
  return n < 2 ? false : n < 4 || (n % 2 == 1 && isPrimeR(n, 3));
}

int main() {
  {
    constexpr LL m = 1073741789LL;  // prime
    constexpr bool x = isPrimeConstexpr(m);
    std::cout << m << " is " <<  (x ? "prime" : "not prime") << '\n';
  }

  // // g++-11: internal compiler error: Segmentation fault: 11 signal terminated program cc1plus
  // {
  //   constexpr LL m = 44657LL * 44683LL;  // 1995408731
  //   constexpr bool x = isPrimeConstexpr(m);
  //   std::cout << m << " is " <<  (x ? "prime" : "not prime") << '\n';
  // }

  // // g++-11: internal compiler error: Segmentation fault: 11 signal terminated program cc1plus
  // {
  //   constexpr LL m = 2147483647LL;  // prime 2^31 - 1
  //   constexpr bool x = isPrimeConstexpr(m);
  //   std::cout << m << " is " <<  (x ? "prime" : "not prime") << '\n';
  // }

  return 0;
}
