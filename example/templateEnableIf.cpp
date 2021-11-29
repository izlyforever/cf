#include <bits/stdc++.h>
#include "/Users/czp/cf/cpplibforCP/cpplib/math/mod.hpp"
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
// see cpplibforCP/cpplib/math/template.hpp for simply

// only accept signed, similarly for unsigned
template<
  typename SignedT, 
  typename TEnabled = std::enable_if_t<std::is_signed<SignedT>::value>
>
SignedT getInverse(SignedT x) {
  return -x;
}

// only type listed blow
template<
  typename SomeT, 
  typename TEnabled = std::enable_if_t<
    std::is_same<float, SomeT>::value ||
    std::is_same<double, SomeT>::value ||
    std::is_same<int, SomeT>::value
  >
>
SomeT getDistanceToMax(SomeT x) {
  return std::numeric_limits<SomeT>::max() - x;
}

// assume that T2 must have 2 times length of T
template<
  typename T1, typename T2,
  typename TEnabled = std::enable_if_t<sizeof(T1) * 2 == sizeof(T2)>
>
T2 squareMinus(T1 x, T2 y) {
  return T2(x) * x - y;
}

// use checker
template<typename T, int n=0>
using modChecker = std::enable_if_t<
    std::is_same_v<MInt<n>, T> ||
    std::is_same_v<ModInt, T> || 
    std::is_same_v<ModLL, T>, T>;

template<typename valT, typename valTEnable = modChecker<valT>>
valT mul(valT x, valT y) {
  return x * y;
}

int main() {
  {
    std::cout << "checker test\n";
    ModInt x(2), y(3);
    // MInt<10> x(2), y(3);
    cerr(mul(x, y));
  }
  {
    std::cout << "getInverse test: int x\n";
    int x;
    std::cin >> x;
    cerr(getInverse(x));
  }
  {
    std::cout << "squareMinus test: int x and float y\n";
    int x;
    float y;
    std::cin >> x >> y;
    cerr(getDistanceToMax(x));
    cerr(getDistanceToMax(y));
  }
  {
    std::cout << "squareMinus test: int32 x and int64 y\n";
    int32_t x;
    int64_t y;
    std::cin >> x >> y;
    cerr(squareMinus(x, y));
  }
  return 0;
}
