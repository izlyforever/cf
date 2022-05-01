#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<typename T>
class A {
 public:
   A(T x) : x_(x) {}
   ~A() {
     std::cout << static_cast<uint64_t>(x_) << std::endl;
   }
  T x_;
};
using A1 = A<uint8_t>;
using A2 = A<uint16_t>;
using A4 = A<uint32_t>;
using A8 = A<uint64_t>;
void solve() {
  std::queue<A1> a1;
  std::queue<A2> a2;
  std::queue<A4> a3;
  std::queue<A8> a4;
  for (int i = 0; i < 16; ++i) {
    a1.emplace(i);
    a2.emplace(i);
    a3.emplace(i);
    a4.emplace(i);
  }
  for (int i = 0; i < 16; ++i) {
    std::cout << std::endl;
    std::cout << i << " a1: " << std::endl;
    a1.pop();
    std::cout << i << " a2: " << std::endl;
    a2.pop();
    std::cout << i << " a3: " << std::endl;
    a3.pop();
    std::cout << i << " a4: " << std::endl;
    a4.pop();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  std::this_thread::sleep_for(std::chrono::seconds(3));
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
