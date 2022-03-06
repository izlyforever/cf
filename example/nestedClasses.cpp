#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class A {
 public:
  int x_;
  A(int x) : x_(x) {
    b.parent = this;
  }
  class B {
   public:
    A* parent;
    int y_;
    LL getAns() {
      return 1LL * parent->x_ * y_;
    }
  } b;
};

void solve() {
  A a(3);
  a.b.y_ = 4;
  cerr(a.b.getAns());
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
