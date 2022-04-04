#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'

// Note That
class CC {
 public:
  int f0() {
    return f(0);
  };
  virtual int f(int x) = 0;
};

class CC1 : public CC {
public:
  int f0() {
    return f(1);
  };
  int f(int x) override;
};

int CC1::f(int x) {
  return x ^ 1;
}

class CC2 : public CC {
public:
  int f0() {
    return f(2);
  };
  int f(int x) override;
};

int CC2::f(int x) {
  return x ^ 2;
}

int main() {
  CC1 c1;
  cerr(c1.f0());
  CC2 c2;
  cerr(c2.f0());

  auto t1 = std::make_shared<CC1>();
  cerr(t1->f0());
  auto t = std::reinterpret_pointer_cast<CC>(t1);
  cerr(t->f0());
  auto t2 = std::reinterpret_pointer_cast<CC2>(t);
  cerr(t2->f0());
  return 0;
}
