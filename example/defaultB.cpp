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
  B1 y;
  // why no build error ?
  cerr(y.f(1));

  // build error
  // cerr(y.f());
  return 0;
}
