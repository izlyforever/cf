#include <bits/stdc++.h>

class A {
 public:
  A() {
    std::cout << "A()" << '\n';
  }
  ~A() {
    std::cout << "~A()" << '\n';
  }
};

class B {
 public:
  B() {
    std::cout << "B()" << '\n';
  }
  ~B() {
    std::cout << "~B()" << '\n';
  }
};

class C {
 public:
  C() {
    std::cout << "C()" << '\n';
  }
  ~C() {
    std::cout << "~C()" << '\n';
  }
};

class ABC {
 public:
  ABC() {
    b = std::make_unique<B>();
    c = std::make_shared<C>();
    a = std::make_shared<A>();
  }
  std::shared_ptr<A> a;
  std::unique_ptr<B> b;
  std::shared_ptr<C> c;
};

int main () {
  {
    ABC abc;
  }
  return 0;
}
