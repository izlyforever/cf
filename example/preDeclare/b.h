#pragma once
#include <bits/stdc++.h>

class A;
class B {
  std::unique_ptr<A> tmp;
 public:
  B();
  int getAns();
  // ~B() = default // this will ce
  // ~B() {} // this will ce
  ~B(); // This is needed
};