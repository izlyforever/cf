#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int a[] = {0x3f3f3f3f, 3, 2};
  auto p = (void*)a;
  std::cout << a << '\n';
  std::cout << p << '\n';
  std::cout << std::hex << (*(int16_t*)(p)) << '\n';
  std::cout << std::hex << (*(int32_t*)(p)) << '\n';

  void** pp = &p;
  std::cout << std::hex << (*(int32_t*)(pp)) << '\n';
  std::cout << std::hex << (*(long*)(pp)) << '\n';

  std::cout << (pp) << '\n';
  ++pp;
  std::cout << (pp) << '\n';
  std::cout << (a + 2) << '\n';
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
