#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'

thread_local int x;
class X {
 public:
  static thread_local std::string s;
  static thread_local int y;
};
thread_local int X::y = 2;
thread_local std::string X::s;
void foo()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  cerr(X::y);
  x = 3;
  cerr(x);
  X::y= 123;
  X::s = "123";
  cerr(X::y);
  cerr(X::s);
}

int main() {
  std::thread t(foo);
  cerr(X::y);
  x = 4;
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  t.join();
  cerr(x);
  X::y = 456;
  X::s = "456";
  cerr(X::y);
  cerr(X::s);
  return 0;
}
