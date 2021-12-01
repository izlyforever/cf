#pragma once
#include <iostream>

class A {
  int x_;
 public:
  A(int x) : x_(x) {}
  // void test(int x);  111111
  void test(int x) { // 不会编译错误，本质上编译器帮你放在两个文件中了？
    long long sum = 0;
    for (int i = 0; i < x; ++i) {
      if (i & 1) sum += i * x_;
      else sum += i / 3 * i + 5 * x_ + 3;
    }
    std::cout << "sum: " << sum << '\n';
  }
};
// 111111 这两个组合会编译错误
// void A::test(int x) {
//   std::cout << x << '\n';
// }