#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'

class A {
 public:
  virtual int f(int x) = 0;
};

class A1 : public A {
public:
  int f(int x = 0) override;
};

int A1::f(int x) {
  return x ^ 1;
}

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
  {
    A1 x;
    cerr(x.f(1));
    cerr(x.f());
  }
  {
    B1 y;
    cerr(y.f(1));

    cerr(y.f());
  }
  return 0;
}
