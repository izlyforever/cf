#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class A {
  mutable std::mutex mutex_;
  std::vector<int> tmp{1};
 public:
  ~A() {
    std::lock_guard _(mutex_);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  void push(int x) {
    std::lock_guard _(mutex_);
    tmp.emplace_back(x);
  }
  int getback() {
    std::lock_guard _(mutex_);
    return tmp.back();
  }
};
A* a;

void f() {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  a->push(123456);
  cerr(a->getback());
}

void solve() {
  a = new A();
  std::thread t(f);
  delete a;
  t.join();
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
