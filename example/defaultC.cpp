#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'

// Note That
class C {
 public:
  virtual int f(int x = 0) = 0;
};

class C1 : public C {
public:
  int f(int x = 1) override;
};

int C1::f(int x) {
  return x ^ 1;
}

class C2 : public C {
public:
  int f(int x = 2) override;
};

int C2::f(int x) {
  return x ^ 2;
}

int main() {
  C1 c1;
  cerr(c1.f());
  C2 c2;
  cerr(c2.f());

  auto t1 = std::make_shared<C1>();
  cerr(t1->f());
  auto t = std::reinterpret_pointer_cast<C>(t1);
  cerr(t->f());
  auto t2 = std::reinterpret_pointer_cast<C2>(t);
  cerr(t2->f());
  return 0;
}
