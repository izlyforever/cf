#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'

class B {
 public:
  virtual int f(int x = 0) = 0;
};

class B1 : public B {
public:
  int f(int x) override;
};

int B1::f(int x) {
  return x ^ 1;
}

int main() {
  // no build error since B::f is not virtual
  B1 y;
  cerr(y.f(1));
  // build error since B::f is calling B::f(int) but not B1::f(int)
  // cerr(y.f());

  auto x1 = std::make_shared<B1>();
  auto x = std::reinterpret_pointer_cast<B>(x1);
  cerr(x->f());
  return 0;
}
