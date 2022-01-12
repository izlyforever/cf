#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

struct Foo {
    Foo(int n = 0) noexcept : bar(n) {
        std::cout << "Foo: constructor, bar = " << bar << '\n';
    }
    ~Foo() {
         std::cout << "Foo: destructor, bar = " << bar << '\n';
    }
    int getBar() const noexcept { return bar; }
private:
    int bar;
};

void solve() {
  std::shared_ptr<Foo> sptr = std::make_shared<Foo>(1);
  {
    auto p = sptr.get();
    cerr("will crash");
    delete p;
    cerr("crash not print");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  // {
  //   sptr.reset();
  // }
  std::shared_ptr<int> a = std::make_shared<int>(13);
  auto b = a;
  a.reset(new int(12));
  if (b) {
    cerr(*b);
  }
  if (a) {
    cerr(*a);
  }
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