#include "a.h"
#include "b.h"

B::B() {
  tmp = std::make_unique<A>();
}
int B::getAns() {
  return tmp->add();
}
B::~B() {}