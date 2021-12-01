#include "b.h"

void B::test(A a, int x) {
  std::cout << "helloB" << '\n';
  a.test(x);
}
