#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class Timer {
 public:
  Timer(std::function<void(void)> f) {
    f_ = std::move(f);
  }
  void sched() {
    f_();
  }
  std::function<void(void)> f_;
};

class A {
 public:
  void test() {
    int x = 123;
    timer.reset(new Timer([this, x]() {
      timer.reset();
      printf("x is %d\n", x);
    }));
    timer->sched();
  }
  std::shared_ptr<Timer> timer;
};

void solve() {
  A x;
  x.test();
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
