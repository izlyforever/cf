#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class A {
 public:
  A() = default;
  ~A() {
    std::cout << "AAA" << '\n';
  }
  int x;
};

class B {
 public:
  B() {
    x = std::make_shared<A>();
  }
  ~B() {
    std::cout << "BBB" << '\n';
  }
  std::shared_ptr<A> x;
};

void solve() {
  {
    B x;
  }
  std::cout << "Solve()" << '\n';
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
