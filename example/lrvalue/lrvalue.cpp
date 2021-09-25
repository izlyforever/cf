#include <iostream>
#include <functional>

class A{
  std::string s;
 public:
  A(std::string&& x) : s(std::move(x)) {}
  A(const A& x) = default;
  A& operator=(const A& x) = default;
  A(A&& x) : s(std::move(x.s)) {
    std::cout << "Construct" << std::endl;
  }
  A& operator=(A&& x) {
    std::cout << "=" << std::endl;
    s = std::move(x.s);
    return *this;
  }
  void print() {
    std::cout << s << std::endl;
  }
  ~A() {
    std::cout << "Bye: " << s << std::endl;
  }
};

class B {
 public:
  int a;
  void print() {
    std::cout << a << '\n';
  }
  B(){}
  B(B&& x) = default;
};


class C {
 public:
  std::string a;
  int b;
  void print() {
    std::cout << a << ": " << b << '\n';
  }
  C(){}
  C(C&& x) = default;
};

class D {
 public:
  int a;
  D() {a = 0; }
  void print() {
    std::cout << a << '\n';
  }
};

void f(D x) {
  x.print();
}

int main () {
  {
    D x;
    x.a = 2;
    f(x);
    f(D());
    auto&& y = x;
    f(y);
  }
  {
    B x;
    x.a = 123;
    B y = std::move(x);
    x.print();
    y.print();
    y.a = 3;
    x.print();
    y.print();
  }
  {
    C x;
    x.a = "123";
    x.b = 10;
    C y = std::move(x);
    x.print();
    y.print();
    y.a = "13";
    y.b = 12;
    x.print();
    y.print();
  }
  {
    int x = 1;
    // int&& y = x;
  }
  int t;
  {
    A x("x");
    A xx = std::move(x);
    A&& y = std::move(xx);
    x.print();
    y.print();
    {
      A z("z");
      y = std::move(z);
      std::cin >> t;
      xx.print();
      z.print();
    }
    std::cin >> t;
    y.print();
  }
  std::cin >> t;
  return 0;
}