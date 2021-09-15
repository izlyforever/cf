#include <iostream>
#include "AImpl.h"
#include "BImpl.h"

void AImpl::do_something() {
  std::cout << "AImpl" << std::endl;
};

void BImpl::do_something() {
  std::cout << "BImpl" << std::endl;
};