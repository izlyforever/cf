#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<typename T>
void f(T a) {
  cerr("?");
}
// template<> is not needed
void f(int x) {
  cerr("what?");
}

template<typename T>
class A{
 public: 
  void out() {
    cerr("?");
  }
};

template<> // is needed
void A<int>::out() {
  cerr("what?");
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  f(10);
  f(1.1);
  A<double> x;
  A<int> y;
  x.out();
  y.out();

  return 0;
}
