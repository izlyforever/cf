#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;


void solve() {
  // https://devdocs.io/cpp/types/endian  C++20 impl
  {
    if (std::endian::native == std::endian::big) {
      std::cout << "big Endian" << std::endl;
    } else {
      std::cout << "small Endian" << std::endl;
    }
  }
  {
    int a = 1;
    auto* ptr = reinterpret_cast<char *>(&a);
    if (*ptr == 1) {
      std::cout << "small Endian" << std::endl;
    } else {
      std::cout << "big Endian" << std::endl;
    }
  }
  {
    union Test {
      uint32_t a;
      uint8_t  b[4];
    } c;
    c.a = 0x12345678;
    if (c.b[0] == 0x12) {
      std::cout << "big Endian" << std::endl;
    } else {
      std::cout << "small Endian" << std::endl;
    }
    for (int i = 0; i < 4; ++i) {
      std::cout << std::hex << (int)c.b[i] << std::endl;
    }
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
